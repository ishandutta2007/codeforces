#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXLN = 17;
vector<int> tree[MAXN];
int depth[MAXN];
int par[MAXLN][MAXN];
vector<int> people[MAXN];
vector<int> st[MAXLN + 1][MAXN];
bool vv[MAXLN + 1][MAXN];
int n;

vector<int> merge(const vector<int> &v1, const vector<int> &v2)
{
    vector<int> ret;
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(ret));
    ret.erase(unique(ret.begin(),ret.end()),ret.end());
    if(ret.size()>10) ret.erase(ret.begin()+10,ret.end());
    return ret;
}

vector<int> &getst(int ln, int t)
{
    if (ln == 0) return people[t];

    if (vv[ln][t] == false)
    {
        vv[ln][t] = true;
        st[ln][t] = merge(getst(ln - 1, t), getst(ln - 1, par[ln - 1][t]));
    }

    return st[ln][t];
}
void dfs(int nod, int parent) {
    for (int next : tree[nod]) {
        if (next == parent) continue;
        depth[next] = depth[nod] + 1;
        par[0][next] = nod;
        dfs(next, nod);
    }
}
void prepare_lca() {
    const int root = 0;
    dfs(root, -1);
    par[0][root] = root;
    for (int i = 1; i < MAXLN; ++i)
        for (int j = 0; j < n; ++j)
            par[i][j] = par[i - 1][par[i - 1][j]];
}
// find lowest common ancestor in tree between u & v
// assumption : must call 'prepare_lca' once before call this
// O(logV)
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    if (depth[u] > depth[v]) {
        for (int i = MAXLN - 1; i >= 0; --i)
            if (depth[u] - (1 << i) >= depth[v])
                u = par[i][u];
    }
    if (u == v) return u;
    for (int i = MAXLN - 1; i >= 0; --i) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

int main()
{
    int m, q;
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1; i < n; i++)
    {
        int a,b ;
        scanf("%d%d",&a,&b);
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    prepare_lca();

    for (int i = 1; i <= m; i++)
    {
        int t;
        scanf("%d",&t);
        --t;
        if (people[t].size() < 10) people[t].push_back(i);
    }

    while (q--)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        int p = lca(a, b);

        vector<int> result = people[p];

        for (int i = MAXLN - 1; i >= 0 && a != p; i--)
        {
            if (depth[par[i][a]] >= depth[p])
            {
                result = merge(result, getst(i, a));
                a = par[i][a];
            }
        }

        for (int i = MAXLN - 1; i >= 0 && b != p; i--)
        {
            if (depth[par[i][b]] >= depth[p])
            {
                result = merge(result, getst(i, b));

                b = par[i][b];
            }
        }

        printf("%d", min(c, (int)result.size()));
        int cnt = 0;
        for (int t : result)
        {
            printf(" %d", t);
            if (++cnt == c) break;
        }
        printf("\n");
    }
}