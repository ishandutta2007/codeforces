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

map<ll, vector<pli>> mapchik;

const ll INF = (ll)2e18;

const int M = (int)35e6;
const int PSZ = (int)3e6;
bool p[M];
int pr[PSZ];
int prSz;

const int N = (int)1e5 + 10;
bool ANS[N];
ll dist[N];

ll euclid(ll x, ll y, ll &k, ll &l) {
	if (y == 0) {
		k = 1;
		l = 0;
		return x;
	}
	ll g = euclid(y, x % y, l, k);
	l -= k * (x / y);
	return g;
}

vector<ll> factorize(ll x) {
	vector<ll> res;
	for (int i = 0; i < prSz; i++) {
		if (x % pr[i]) continue;
		res.push_back(pr[i]);
		while(x % pr[i] == 0) x /= pr[i];
	}
	if (x > 1) res.push_back(x);
	return res;
}

void solve(ll k, vector<pli> queries) {
	vector<ll> a = factorize(k);
	int n = (int)a.size();
	if (n == 0) {
		return;
	} else if (n == 1) {
		for (pli q : queries) {
			ANS[q.second] = q.first % a[0] == 0;
		}
		return;
	} else if (n == 2) {
		ll r = 0, s = 0;
		if (euclid(a[0], a[1], r, s) != 1) throw;
		s %= a[0];
		if (s < 0) s += a[0];
		for (pli q : queries) {
			ll z = ((s * (q.first % a[0])) % a[0]) * a[1];
			ANS[q.second] = z <= q.first;
		}
		return;
	}
	int m = a[0];
	for (int i = 0; i < m; i++)
		dist[i] = INF;
	dist[0] = 0;
	set<pli> setik;
	for (int i = 0; i < m; i++)
		setik.insert(mp(dist[i], i));
	while(!setik.empty()) {
		int v = setik.begin()->second;
		setik.erase(setik.begin());
		for (int i = 1; i < n; i++) {
			int u = (v + a[i]) % m;
			ll w = dist[v] + a[i];
			if (w >= dist[u]) continue;
			setik.erase(mp(dist[u], u));
			dist[u] = w;
			setik.insert(mp(dist[u], u));
		}
	}
	for (pli q : queries) {
		ANS[q.second] = dist[q.first % m] <= q.first;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < M; i++)
		p[i] = 1;
	for (int x = 2; x < M; x++) {
		if (!p[x]) continue;
		pr[prSz++] = x;
		for (int y = 2 * x; y < M; y += x)
			p[y] = 0;
	}

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		mapchik[k].push_back(mp(n, i));
	}
	for (auto it : mapchik) {
		solve(it.first, it.second);
	}

	for (int i = 0; i < t; i++)
		if (ANS[i])
			printf("YES\n");
		else
			printf("NO\n");

	return 0;
}