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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)4e6 + 7;
int a[N], b[N];
ll S;
int ans = 0;
int n, m;
int c[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i + 1]);
		c[i + 1] += c[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			int x = c[j] - c[i], y = j - i;
			a[x] = max(a[x], y);
		}
	n = m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i + 1]);
		c[i + 1] += c[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			int x = c[j] - c[i], y = j - i;
			b[x] = max(b[x], y);
		}

	for (int i = 1; i < N; i++) {
		a[i] = max(a[i], a[i - 1]);
		b[i] = max(b[i], b[i - 1]);
	}
	scanf("%lld", &S);
	ll r = N - 1;
	for (ll l = 1; l < N; l++) {
		while(l * r > S) r--;
		ans = max(ans, a[l] * b[r]);
	}
	printf("%d\n", ans);

	return 0;
}