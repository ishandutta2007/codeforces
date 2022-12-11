#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200001;
vector<int> g[N];
bool bl[N];
int size[N];
char lab[N];
int mask[N];
ll cur[N];
ll ans[N];
unordered_map<int, int> cnt[N];
int gl_cnt[1 << 20];

void dfs1(int v, int prev)
{
    size[v] = 1;
    for(int u: g[v])
        if(!bl[u] && u != prev)
        {
            dfs1(u, v);
            size[v] += size[u];
        }
}

int centroid(int v, int prev, int n)
{
    for(int u: g[v])
        if(!bl[u] && u != prev && size[u] * 2 > n)
            return centroid(u, v, n);
    return v;
}

inline int update(int mask, char c)
{
    return mask ^ (1 << (c - 'a'));
}

int dk, drmask;
void dfs2(int v, int prev)
{
    mask[v] = update(mask[prev], lab[v]);
    gl_cnt[mask[v] ^ drmask] += dk;
    for(int u: g[v])
        if(!bl[u] && u != prev)
            dfs2(u, v);
}

void dfs3(int v, int prev)
{
    cur[v] = gl_cnt[mask[v]];
    for(int i = 0; i < 20; i++)
        cur[v] += gl_cnt[mask[v] ^ (1 << i)];
    for(int u: g[v])
        if(!bl[u] && u != prev)
        {
            dfs3(u, v);
            cur[v] += cur[u];
        }
    ans[v] += cur[v];
}

void go(int start)
{
    dfs1(start, 0);
    int root = centroid(start, 0, size[start]);
    mask[root] = update(0, lab[root]);
    drmask = mask[root];
    dk = 1;
    for(int u: g[root])
        if(!bl[u]) dfs2(u, root);
    cur[root] = gl_cnt[mask[root]];
    for(char c = 'a'; c <= 't'; c++)
        cur[root] += gl_cnt[update(mask[root], c)];
    gl_cnt[0]++;
    for(int u: g[root])
        if(!bl[u])
        {
            dk = -1;
            dfs2(u, root);
            dfs3(u, root);
            dk = 1;
            dfs2(u, root);
            cur[root] += cur[u];
        }
    ans[root] += cur[root] / 2;
    dk = -1;
    for(int u: g[root])
        if(!bl[u]) dfs2(u, root);
    gl_cnt[0]--;
    bl[root] = true;
    for(int u: g[root])
        if(!bl[u]) go(u);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%s", lab + 1);
    go(1);
    for(int i = 1; i <= n; i++)
        printf("%lld ", ans[i] + 1);
    puts("");
}