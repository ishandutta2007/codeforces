#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
const ll inf = (ll) 1e18;
int n, m;
vector<pi> g[maxn];
ll dist[maxn][2][2];
void dijkstra() {
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                dist[i][x][y] = inf;
    }
    dist[1][0][0] = 0;
    set<pair<pair<ll, int>, pi>> q;
    q.insert(mp(mp(0LL, 1), mp(0, 0)));
    while (!q.empty()) {
        auto cur = *q.begin();
        q.erase(q.begin());
        for (auto e : g[cur.fi.se]) {
            for (int x = cur.se.fi; x < 2; x++) {
                for (int y = cur.se.se; y < 2; y++) {
                    ll wei = cur.fi.fi + e.se;
                    if (x > cur.se.fi) wei -= e.se;
                    if (y > cur.se.se) wei += e.se;
                    if (wei < dist[e.fi][x][y]) {
                        q.erase(mp(mp(dist[e.fi][x][y], e.fi), mp(x, y)));
                        dist[e.fi][x][y] = wei;
                        q.insert(mp(mp(dist[e.fi][x][y], e.fi), mp(x, y)));
                    }
                }
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
    }
    dijkstra();
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dist[i][1][1]);
    }
    return 0;
}