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

const ll INF = (ll)1e15;
const int N = 300300;
int n, m, k, q;
ll ANS[N];
vector<int> g[N];
vector<pii> Q[N];
int par[N];
vector<int> a[N];
ll ed[N][3];
pli ord[N];
set<pli> setik;
ll dist[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < m; i++) {
		scanf("%lld%lld%lld", &ed[i][0], &ed[i][1], &ed[i][2]);
		ed[i][0]--;
		ed[i][1]--;
		g[ed[i][0]].push_back(i);
		g[ed[i][1]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (i < k) {
			dist[i][0] = 0;
			dist[i][1] = i;
		} else
			dist[i][0] = INF;
		setik.insert(mp(dist[i][0], i));
	}
	while(!setik.empty()) {
		int v = setik.begin()->second;
		eprintf("%d\n", v);
		setik.erase(setik.begin());
		for (int id : g[v]) {
			int u = ed[id][0] ^ ed[id][1] ^ v;
			ll w = dist[v][0] + ed[id][2];
			if (w >= dist[u][0]) continue;
			setik.erase(mp(dist[u][0], u));
			dist[u][0] = w;
			dist[u][1] = dist[v][1];
			setik.insert(mp(dist[u][0], u));
		}
	}
	for (int i = 0; i < m; i++) {
		ed[i][2] += dist[ed[i][0]][0] + dist[ed[i][1]][0];
		ed[i][0] = dist[ed[i][0]][1];
		ed[i][1] = dist[ed[i][1]][1];
		ord[i] = mp(ed[i][2], i);
	}
	sort(ord, ord + m);
	for (int i = 0; i < k; i++) {
		par[i] = i;
		a[i].push_back(i);
	}
//	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		Q[v].push_back(mp(u, i));
		Q[u].push_back(mp(v, i));
	}
	for (int i = 0; i < m; i++) {
		eprintf("%d\n", i);
		int id = ord[i].second;
		int v = ed[id][0], u = ed[id][1];
		v = par[v];
		u = par[u];
		if (v == u) continue;
		if ((int)a[v].size() > (int)a[u].size()) swap(v, u);
		for (int w : a[v]) {
			for (pii QQ : Q[w]) {
				int z = QQ.first;
				if (par[z] == u)
					ANS[QQ.second] = ed[id][2];
			}
		}
		for (int w : a[v]) {
			par[w] = u;
			a[u].push_back(w);
		}
	}
	for (int i = 0; i < q; i++)
		printf("%lld\n", ANS[i]);

	return 0;
}