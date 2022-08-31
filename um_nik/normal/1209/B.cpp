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

const int N = 733;
int n;
int a[N][2];
int b[N][N];
char s[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);
	for (int i = 0; i < n; i++)
		b[0][i] = (int)(s[i] - '0');
	for (int t = 1; t < N; t++) {
		for (int i = 0; i < n; i++) {
			b[t][i] = b[t - 1][i];
			if (t >= a[i][1] && (t - a[i][1]) % a[i][0] == 0)
				b[t][i] ^= 1;
		}
	}
	int ans = 0;
	for (int t = 0; t < N; t++) {
		int cur = 0;
		for (int i = 0; i < n; i++)
			cur += b[t][i];
		ans = max(ans, cur);
	}
	printf("%d\n", ans);

	return 0;
}