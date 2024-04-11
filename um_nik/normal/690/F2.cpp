#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
#define mp make_pair


const ll MOD = (ll)1e9 + 7;
const ll P = 31;

ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}

const int N = 111;
ll p[N];

pli multHashes(pli x, pli y)
{
    return mp(add(mult(x.first, p[y.second]), y.first), x.second + y.second);
}

pli getVectorHash(vector<pli> a)
{
    pli res = mp(0, 0);
    sort(a.begin(), a.end());
    for (pli x : a)
        res = multHashes(res, x);
    return res;
}

int n;
vector<int> G[N][N];
int ed[N];
vector<pli> initial_hashes;
bool used[N];
int sz[N];
vector<int> T[N];
vector<int> TT[N];

pli getTreeHash(int v, int par, vector<int> g[N])
{
    int deg = 1;
    vector<pli> a;
    for (int u : g[v])
    {
        if (u == par) continue;
        deg++;
        a.push_back(getTreeHash(u, v, g));
    }
    return multHashes(mp(deg, 1), getVectorHash(a));
}

void dfs(int v, vector<int> g[N])
{
    used[v] = 1;
    sz[v] = 1;
    for (int u : g[v])
    {
        if (used[u]) continue;
        dfs(u, g);
        sz[v] += sz[u];
    }
    return;
}
pii getCentroids(vector<int> g[N], int v)
{
    dfs(v, g);
    int u = v;
    while(true)
    {
        int w = -1;
        for (int x : g[u])
        {
            if (sz[x] >= sz[u]) continue;
            if (2 * sz[x] > sz[v])
                w = x;
        }
        if (w == -1) break;
        u = w;
    }
    int w = -1;
    for (int x : g[u])
    {
        if (sz[x] >= sz[u]) continue;
        if (2 * sz[x] >= sz[v])
            w = x;
    }
    if (w == -1) w = u;
    return mp(u, w);
}

pli getForestHash(vector<int> g[N])
{
    for (int i = 0; i < n; i++)
    {
        sz[i] = 0;
        used[i] = 0;
    }
    vector<pli> a;
    for (int v = 0; v < n; v++)
    {
        if (used[v]) continue;
        pii cc = getCentroids(g, v);
        vector<pli> h;
        h.push_back(getTreeHash(cc.first, -1, g));
        h.push_back(getTreeHash(cc.second, -1, g));
        a.push_back(getVectorHash(h));
    }
    return getVectorHash(a);
}

void read()
{
    scanf("%d%d", &n, &n);
    for (int it = 0; it < n; it++)
    {
        for (int i = 0; i < n; i++)
            G[it][i].clear();
        scanf("%d", &ed[it]);
        for (int i = 0; i < ed[it]; i++)
        {
            int v, u;
            scanf("%d%d", &v, &u);
            v--;u--;
            G[it][v].push_back(u);
            G[it][u].push_back(v);
        }
    }
    return;
}

bool acyclicDfs(int v, int par, vector<int> g[N])
{
    used[v] = 1;
    int parCnt = 0;
    for (int u : g[v])
    {
        if (u == par)
        {
            parCnt++;
            if (parCnt > 1) return false;
            continue;
        }
        if (used[u]) return false;
        if (!acyclicDfs(u, v, g)) return false;
    }
    return true;
}
bool acyclic(vector<int> g[N])
{
    for (int i = 0; i < n; i++)
        used[i] = 0;
    for (int v = 0; v < n; v++)
    {
        if (used[v]) continue;
        if (!acyclicDfs(v, -1, g)) return false;
    }
    return true;
}

bool checkTree()
{
    vector<pli> a;
    for (int it = 0; it < n; it++)
    {
        for (int v = 0; v < n; v++)
        {
            TT[v].clear();
            if (v == it) continue;
            for (int x : T[v])
                if (x != it)
                    TT[v].push_back(x);
        }
        a.push_back(getForestHash(TT));
    }
    sort(a.begin(), a.end());
    return a == initial_hashes;
}

void printTree()
{
    printf("YES\n");
    for (int v = 0; v < n; v++)
        for (int u : T[v])
            if (v < u)
                printf("%d %d\n", v + 1, u + 1);
    return;
}

bool solve2(int fId)
{
    int v = -1;
    for (int i = 0; v == -1 && i < n; i++)
    {
        if (G[fId][i].empty())
            v = i;
    }
    if (v == -1) return false;
    for (int u = 0; u < n; u++)
    {
        if (v == u) continue;
        for (int i = 0; i < n; i++)
            T[i] = G[fId][i];
        T[v].push_back(u);
        T[u].push_back(v);
        if (checkTree())
        {
            printTree();
            return true;
        }
    }
    return false;
}

void solve()
{
    read();
    for (int i = 0; i < n; i++)
    {
        if (ed[i] >= n - 1)
        {
            printf("NO\n");
            return;
        }
        if (!acyclic(G[i]))
        {
            printf("NO\n");
            return;
        }
    }
    int it = -1;
    for (int i = 0; i < n && it == -1; i++)
        if (ed[i] == n - 2)
            it = i;
    if (it == -1)
    {
        printf("NO\n");
        return;
    }
    initial_hashes.clear();
    for (int i = 0; i < n; i++)
        initial_hashes.push_back(getForestHash(G[i]));
    sort(initial_hashes.begin(), initial_hashes.end());

    if (!solve2(it)) printf("NO\n");
    return;
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = mult(p[i - 1], P);
    return;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    init();

    int t;
    scanf("%d", &t);
    while(t--)
        solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}