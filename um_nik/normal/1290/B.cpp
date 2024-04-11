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
const int A = 26;
char s[N];
int n;
int a[N][A];

bool solve(int l, int r) {
	if (l + 1 == r) return true;
	int cnt = 0;
	for (int i = 0; i < A; i++)
		if (a[l][i] != a[r][i])
			cnt++;
	if (cnt == 1) return false;
	if (cnt >= 3) return true;
	return s[l] != s[r - 1];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < A; c++)
			a[i + 1][c] = a[i][c];
		a[i + 1][(int)(s[i] - 'a')]++;
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		if (solve(l, r))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}