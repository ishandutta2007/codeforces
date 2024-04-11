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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define mp make_pair

const ll INF = (ll)1e12;
const int N = (int)1e6 + 10;
int n, m, k;
ll a[N];
ll b[N];
ll c[N];
ll ANS = INF * N;
vector<pli> d[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	while(m--) {
		int t, v, u;
		ll w;
		scanf("%d%d%d%lld", &t, &v, &u, &w);
		if (v == 0)
			v = -u;
		d[t].push_back(mp(w, v));
	}
	for (int i = 1; i <= n; i++)
		a[i] = INF;
	for (int i = 0; i < N; i++)
		b[i] = c[i] = INF;
	ll val = n * INF;
	for (int i = 0; i < N; i++) {
		for (pli t : d[i]) {
			if (t.second < 0) continue;
			int id = t.second;
			ll w = t.first;
			if (w >= a[id]) continue;
			val -= a[id];
			a[id] = w;
			val += a[id];
		}
		b[i] = val;
	}
	for (int i = 1; i <= n; i++)
		a[i] = INF;
	val = n * INF;
	for (int i = N - 1; i >= 0; i--) {
		for (pli t : d[i]) {
			if (t.second > 0) continue;
			int id = -t.second;
			ll w = t.first;
			if (w >= a[id]) continue;
			val -= a[id];
			a[id] = w;
			val += a[id];
		}
		c[i] = val;
	}
	for (int i = 0; i + k + 1 < N; i++)
		ANS = min(ANS, b[i] + c[i + k + 1]);
	if (ANS >= INF)
		printf("-1\n");
	else
		printf("%lld\n", ANS);

	return 0;
}