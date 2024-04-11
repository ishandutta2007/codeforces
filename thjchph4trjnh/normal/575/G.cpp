#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n, m;
vii adj[maxn];
int d[maxn];
int D[maxn];
int o[maxn];
int p[maxn];
int l[maxn];
vi group[maxn];
vi vans, lans;
vector<pair<int, pair<int, pair<int, int> > > > tmp;

void solve() {
	ms(d, 0x3f); ms(D, 0x3f); ms(o, 0); ms(p, -1); ms(l, 0x3f);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	priority_queue<pair<pi, int> > pq;
	pq.push(make_pair(make_pair(0, 0), n - 1)); d[n - 1] = D[n - 1] = 0;
	while (sz(pq)) {
		int u = pq.top().second; pq.pop();
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].first;
			int k = D[u] + 1;
			if (D[u] == 0 && adj[u][i].second == 0) k = 0;
			if (D[v] > k) {
				D[v] = k;
				if (k == 0) {
					if (d[v] > d[u] + 1) {
						d[v] = d[u] + 1;
						p[v] = u;
						l[v] = 0;
					}
				}
				pq.push(make_pair(make_pair(-D[v], -d[v]), v));
			}
		}
	}
	FOR(i, 0, n) if (D[i] <= n) group[D[i]].push_back(i);
	FOR(i, 0, n) {
		FOR(j, 0, sz(group[i])) {
			int u = group[i][j];
			FOR(k, 0, sz(adj[u])) {
				int v = adj[u][k].first;
				if (D[v] == i + 1) {
					if (p[v] == -1) {p[v] = u; l[v] = adj[u][k].second; d[v] = d[u] + 1;}
					else if (make_pair(o[p[v]], make_pair(l[v], d[v])) > make_pair(o[u], make_pair(adj[u][k].second, d[u] + 1))) {
						p[v] = u; l[v] = adj[u][k].second; d[v] = d[u] + 1;
					}
				}
			}
		}
		FOR(j, 0, sz(group[i + 1])) {
			int u = group[i + 1][j];
			tmp.push_back(make_pair(o[p[u]], make_pair(l[u], make_pair(d[u], u))));
		}
		sort(tmp.begin(), tmp.end());
		int cnt = 0;
		FOR(j, 0, sz(tmp)) {
			int u = tmp[j].second.second.second;
			o[u] = cnt;
			if (j < sz(tmp) - 1 && make_pair(tmp[j].first, make_pair(tmp[j].second.first, tmp[j].second.second.first)) != make_pair(tmp[j + 1].first, make_pair(tmp[j + 1].second.first, tmp[j + 1].second.second.first))) cnt++;
		}
		tmp.clear();
	}
	//l[n - 1] = 0;//; return;
	int cur = 0;
	while (cur != n - 1) {
		vans.push_back(cur);
		lans.push_back(l[cur]);
		cur = p[cur];
	}
	bool flag = false;
	FORd(i, sz(lans), 0) {
		if (flag || lans[i] > 0) {
			printf("%d", lans[i]);
			flag = true;
		}
	}
	if (!flag) printf("0");
	printf("\n%d\n", sz(vans) + 1);
	FOR(i, 0, sz(vans)) printf("%d ", vans[i]); printf("%d ", n - 1);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}