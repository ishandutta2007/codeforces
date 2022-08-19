#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int fenv[3][N];
set<int> setik[3];
int n;
char s[N];
int c[3];
int a[3], b[3];

int getType(char w) {
	if (w == 'R') return 0;
	if (w == 'S') return 1;
	if (w == 'P') return 2;
	throw;
}

void addFenv(int k, int r, int dx) {
	for (; r < n; r |= r + 1)
		fenv[k][r] += dx;
}
int getFenv(int k, int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[k][r];
	return res;
}
int getSum(int k, int l, int r) {
	return getFenv(k, r - 1) - getFenv(k, l - 1);
}

int answer() {
	for (int i = 0; i < 3; i++) {
		c[i] = getFenv(i, n - 1);
		if (c[i] == n) return n;
	}
	for (int i = 0; i < 3; i++)
		if (c[i] == 0)
			return c[(i + 1) % 3];
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		int l = *setik[i].begin(), r = *setik[i].rbegin();
		a[i] = l;
		b[i] = r;
		ans += getSum((i + 2) % 3, l + 1, r);
	}
	sort(a, a + 3);
	sort(b, b + 3);
	return ans + a[1] + (n - b[1] - 1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		int t = getType(s[i]);
		addFenv(t, i, 1);
		setik[t].insert(i);
	}
	printf("%d\n", answer());
	while(q--) {
		int p;
		char w;
		scanf("%d %c", &p, &w);
		p--;
		int t = getType(s[p]);
		addFenv(t, p, -1);
		setik[t].erase(p);
		s[p] = w;
		t = getType(s[p]);
		addFenv(t, p, 1);
		setik[t].insert(p);
		printf("%d\n", answer());
	}

	return 0;
}