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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 130000;
int n, m;
vi adj1[maxn];
vi adj2[maxn];
bool flag[maxn];
bool vis[maxn];
bool f[maxn];
int size[maxn];
int lev[maxn];
int d[maxn];
vii ans;

void dfs1(int u) {
	vis[u] = 1;
	f[u] |= flag[u];
	FOR(i, 0, sz(adj1[u])) {
		int v = adj1[u][i];
		if (!vis[v]) {
			dfs1(v);
			f[u] |= f[v];
		}
	}
}

void dfs2(int u, int p) {
    size[u] = 1;
    FOR(i, 0, adj2[u].size()){
        int v = adj2[u][i];
        if (v != p){
            dfs2(v, u);
            size[u] += size[v];
        }
    }
}

int findcenter(int u) {
    int p = -1;
    dfs2(u, -1);
    int cap = size[u] / 2;
    while(1) {
        bool found = false;
        FOR(i, 0, adj2[u].size()) {
            int v = adj2[u][i];
            if (v != p && size[v] > cap) {
                found = true;
                p = u;
                u = v;
                break;
            }
        }
        if (!found) return u;
    }
}

void trace(int u, int p = -1) {
	d[u] = u;
	FOR(i, 0, sz(adj2[u])) {
		int v = adj2[u][i];
		if (v != p) {
			lev[v] = lev[u] + 1;
			trace(v, u);
			if (make_pair(lev[d[u]], -d[u]) < make_pair(lev[d[v]], -d[v])) d[u] = d[v];
			if (p == -1) ans.push_back(make_pair(-lev[d[v]], d[v]));
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj1[u].push_back(v); adj1[v].push_back(u);
	}
	int t = INF;
	FOR(i, 0, m) {int u; scanf("%d", &u); u--; flag[u] = 1; t = min(t, u);}
	FOR(i, 0, n) if (flag[i]) {dfs1(i); break;}
	FOR(i, 0, n) FOR(j, 0, sz(adj1[i])) {
		int k = adj1[i][j];
		if (f[i] && f[k]) {
			adj2[i].push_back(k);
		}
	}
	int ct; FOR(i, 0, n) if (f[i]) {ct = findcenter(i); break;}
	trace(ct);
	sort(ans.begin(), ans.end());
	int tot = -1; FOR(i, 0, n) tot += f[i];
	if (tot <= 2) {printf("%d\n%d", t + 1, tot); return;}
	printf("%d\n%d", min(ans[0].second, ans[1].second) + 1, 2 * tot + ans[0].first + ans[1].first);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}