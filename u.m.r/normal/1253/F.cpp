#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n, m, k, q;
vector<PII> E[MAXN];
ll dis[MAXN];
int vis[MAXN];
const ll INF = 1ll << 60;

struct event {
    int x, y;
    ll cost;
};

vector<event> ee;
int fa[MAXN];
int getfather(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = getfather(fa[x]);
}
const int DEP = 20;
int f[MAXN][DEP];
ll val[MAXN];
int dep[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        E[x].push_back(PII(y, z));
        E[y].push_back(PII(x, z));
    }
    typedef pair<ll, int> PLI;
    set<PLI> mp;
    for (int i = k + 1; i <= n; i++) 
        dis[i] = INF, vis[i] = false, mp.insert(PLI(dis[i], i));
    for (int i = 1; i <= k; i++) {
        dis[i] = 0;
        vis[i] = false;
        mp.insert(PLI(dis[i], i));
    }
    while (!mp.empty()) {
        auto nico = mp.begin();
        ll d = nico->first;
        int x = nico->second;
        mp.erase(nico);
        vis[x] = true;
        for (auto &yy : E[x]) {
            int y = yy.first, z = yy.second;
            if (dis[y] > dis[x] + z) {
                mp.erase(PLI(dis[y], y));
                dis[y] = dis[x] + z;
                mp.insert(PLI(dis[y], y));
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        for (auto &y : E[x]) {
            if (x < y.first) {
                ee.push_back((event){x, y.first, y.second + dis[x] + dis[y.first]});
            }
        }
    }
    sort(ee.begin(), ee.end(), [](const event &a, const event &b) {
        return a.cost < b.cost;
    });
    int nn = n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (auto &e : ee) {
        int p = getfather(e.x);
        int q = getfather(e.y);
        if (p != q) {
            nn++;
            val[nn] = e.cost;
            fa[nn] = nn;
            f[p][0] = nn;
            f[q][0] = nn;
            fa[p] = fa[q] = nn;
        }
    }
    dep[nn] = 1;
    for (int i = nn - 1; i >= 1; i--) {
        dep[i] = dep[f[i][0]] + 1;
    }
    for (int i = 1; i < DEP; i++) {
        for (int j = 1; j <= nn; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
    // scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (dep[x] < dep[y]) swap(x, y);
        int delta = dep[x] - dep[y];
        for (int j = 0; j < DEP; j++) {
            if ((delta >> j) & 1) {
                x = f[x][j];
                delta ^= (1 << j);
            }
        }
        for (int j = DEP - 1; j >= 0; j--) {
            if (f[x][j] != f[y][j]) {
                x = f[x][j];
                y = f[y][j];
            }
        }
        while (x != y) {
            x = f[x][0];
            y = f[y][0];
        }
        printf("%lld\n", val[x]);
    }
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}