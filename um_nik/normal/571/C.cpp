#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 200100;
int n, m;
int ans[N];
int g[N][2][2];
int deg[N];
bool ok[N];
vector<int> G[N];
int sz[N], osz[N];

void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sz[i]);
        G[i].resize(sz[i]);
        for (int j = 0; j < sz[i]; j++)
        {
            scanf("%d", &G[i][j]);
            int v = abs(G[i][j]);
            int val = (int)(G[i][j] == v);
            g[v][deg[v]][0] = i;
            g[v][deg[v]][1] = val;
            deg[v]++;
        }
    }
    for (int x = 1; x <= m; x++)
    {
        ans[x] = -1;
        if (deg[x] == 0)
            continue;
        if (deg[x] == 1)
        {
            ans[x] = g[x][0][1];
            ok[g[x][0][0]] = true;
        }
        if (deg[x] == 2 && g[x][0][1] == g[x][1][1])
        {
            ans[x] = g[x][0][1];
            for (int i = 0; i < 2; i++)
                ok[g[x][i][0]] = true;
        }
    }
    return;
}

set<pii> setik;

void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (ok[i]) continue;
        setik.insert(mp(sz[i], i));
        osz[i] = sz[i];
    }
    while(!setik.empty())
    {
        int v = setik.begin()->second;
        setik.erase(setik.begin());
        if (sz[v] == 0)
        {
            printf("NO\n");
            return;
        }
        ok[v] = true;
        for (int i = 0; i < osz[v]; i++)
        {
            int p = G[v][i];
            int z = abs(p);
            int val = (int)(z == p);
            if (ans[z] != -1) continue;
            ans[z] = val;
            for (int j = 0; j < 2; j++)
            {
                int u = g[z][j][0];
                if (u == v) continue;
                if (ok[u]) continue;
                setik.erase(mp(sz[u], u));
                sz[u]--;
                setik.insert(mp(sz[u], u));
            }
            break;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= m; i++)
        printf("%d", (ans[i] == -1 ? 1 : ans[i]));
    printf("\n");
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    solve();

    return 0;
}