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
char s[N], t[N];
int a[N], b[N];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s %s", s, t);
	n = strlen(s);
	m = strlen(t);
	int pos = 0;
	a[0] = -1;
	for (int i = 0; i < m; i++) {
		while(s[pos] != t[i]) pos++;
		a[i + 1] = pos;
		pos++;
	}
	pos = n - 1;
	b[m] = n;
	for (int i = m - 1; i >= 0; i--) {
		while(s[pos] != t[i]) pos--;
		b[i] = pos;
		pos--;
	}
	int ans = 0;
	for (int i = 0; i <= m; i++)
		ans = max(ans, b[i] - a[i] - 1);
	printf("%d\n", ans);

	return 0;
}