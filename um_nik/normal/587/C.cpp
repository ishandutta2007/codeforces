#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100100;
const int L = 18;
const int K = 10;
vector<int> g[N];
int par[N][L];
vector<int> a[N][L];
int n;
int q;
bool used[N];
int h[N];

vector<int> merge(vector<int> A, vector<int> B)
{
    vector<int> R;
    int it1 = 0, it2 = 0;
    while(it1 + it2 < K && (it1 < (int)A.size() || it2 < (int)B.size()))
    {
        if (it1 == (int)A.size())
            R.push_back(B[it2++]);
        else if (it2 == (int)B.size())
            R.push_back(A[it1++]);
        else if (A[it1] < B[it2])
            R.push_back(A[it1++]);
        else
            R.push_back(B[it2++]);
    }
    return R;
}

void read()
{
    int m;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < m; i++)
    {
        int v;
        scanf("%d", &v);
        v--;
        if ((int)a[v][0].size() == K) continue;
        a[v][0].push_back(i + 1);
    }
    return;
}

void dfs(int v)
{
    used[v] = 1;
    for (int u : g[v])
    {
        if (used[u]) continue;
        h[u] = h[v] + 1;
        par[u][0] = v;
        for (int i = 1; i < L; i++)
        {
            if (par[u][i - 1] == -1)
            {
                par[u][i] = -1;
                a[u][i] = a[u][i - 1];
                continue;
            }
            int w = par[u][i - 1];
            par[u][i] = par[w][i - 1];
            a[u][i] = merge(a[u][i - 1], a[w][i - 1]);
        }
        dfs(u);
    }
    return;
}

int up(int v, int dh)
{
    for (int k = L - 1; k >= 0; k--)
    {
        if ((1 << k) <= dh)
        {
            dh -= 1 << k;
            v = par[v][k];
        }
    }
    return v;
}
int LCA(int v, int u)
{
    if (h[v] > h[u]) swap(v, u);
    u = up(u, h[u] - h[v]);
    if (v == u) return v;
    for (int k = L - 1; k >= 0; k--)
    {
        if (par[v][k] != par[u][k])
        {
            v = par[v][k];
            u = par[u][k];
        }
    }
    return par[v][0];
}

void precalc()
{
    for (int i = 0; i < L; i++)
        par[0][i] = -1;
    for (int i = 1; i < L; i++)
        a[0][i] = a[0][0];
    dfs(0);
    return;
}

vector<int> getOnPath(int v, int dh)
{
    vector<int> res;
    for (int k = L - 1; k >= 0; k--)
    {
        if ((1 << k) <= dh)
        {
            dh -= 1 << k;
            res = merge(res, a[v][k]);
            v = par[v][k];
        }
    }
    return res;
}

void query()
{
    int v, u, B;
    scanf("%d%d%d", &v, &u, &B);
    v--;u--;
    if (v == u)
    {
        B = min(B, (int)a[v][0].size());
        printf("%d ", B);
        for (int i = 0; i < B; i++)
            printf("%d ", a[v][0][i]);
        printf("\n");
        return;
    }
    int w = LCA(v, u);
    vector<int> res = merge(getOnPath(v, h[v] - h[w]), getOnPath(u, h[u] - h[w]));
    res = merge(res, a[w][0]);
    B = min(B, (int)res.size());
    printf("%d ", B);
    for (int i = 0; i < B; i++)
        printf("%d ", res[i]);
    printf("\n");
    return;
}

int main()
{
    read();
    precalc();
    while(q--)
        query();

    return 0;
}