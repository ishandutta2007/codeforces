#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int r[N];
int col[N];
vector<int> g[N];
int qa[N];
int qb[N];
int n;

const int M = 1000000;
int u[M];
int v[M];
int w[M];

void dfs(int v, int prev)
{
    col[v] = 3 - col[prev];
    for(int u: g[v])
        if(u != prev) dfs(u, v);
}

inline int Find(int k)
{
    return r[k] == k ? k : (r[k] = Find(r[k]));
}

inline bool Union(int a, int b)
{
    a = Find(a); b = Find(b);
    if(a == b) return false;
    r[a] = b;
    return true;
}

struct edge
{
    int a, b, w;
};

inline bool operator<(const edge &a, const edge &b)
{
    return a.w > b.w;
}

struct answer
{
    vector<edge> mst;
    int value;
    answer() = default;
    answer(int a, int b)
    {
        vector<edge> e;
        for(int i = a; i < b; i++)
            e.push_back({u[i], v[i], w[i]});
        sort(e.begin(), e.end());
        value = -1;
        algo(e);
    }
    
    void algo(const vector<edge> &e)
    {
        for(int i = 1; i <= n; i++)
        {
            r[i] = i;
            col[i] = 0;
            g[i].clear();
        }
        col[0] = 1;
        vector<edge> other;
        for(auto &ed: e)
        {
            int a = ed.a, b = ed.b, w = ed.w;
            if(Union(a, b))
            {
                mst.push_back(ed);
                g[a].push_back(b);
                g[b].push_back(a);
            }
            else other.push_back(ed);
        }
        for(int i = 1; i <= n; i++)
            if(!col[i]) dfs(i, 0);
        for(auto &ed: other)
            if(col[ed.a] == col[ed.b])
                value = max(value, ed.w);
    }
};

answer operator+(const answer &a, const answer &b)
{
    answer ans;
    auto &ma = a.mst, &mb = b.mst;
    vector<edge> e(ma.size() + mb.size());
    merge(ma.begin(), ma.end(), mb.begin(), mb.end(), e.begin());
    ans.value = max(a.value, b.value);
    ans.algo(e);
    return ans;
}

const int offset = 1 << 11;
answer tree[offset << 1];

int algo(int a, int b)
{
    a += offset; b += offset;
    answer ans = tree[a++];
    while(a < b)
    {
        if(a & 1) ans = ans + tree[a++];
        if((b & 1) == 0) ans = ans + tree[b--];
        a >>= 1;
        b >>= 1;
    }
    if(a == b) ans = ans + tree[a];
    return ans.value;
}

int main()
{
    vector<int> x;
    int m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < m; i++)
        scanf("%d %d %d", u + i, v + i, w + i);
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", qa + i, qb + i);
        x.push_back(qa[i]);
        x.push_back(qb[i] + 1);
    }
    sort(x.begin(), x.end());
    for(int i = 0; i + 1 < x.size(); i++)
        tree[i+offset] = answer(x[i] - 1, x[i+1] - 1);
    for(int i = offset - 1; i > 0; i--)
        tree[i] = tree[i+i] + tree[i+i+1];
    for(int i = 0; i < q; i++)
    {
        int a = lower_bound(x.begin(), x.end(), qa[i]) - x.begin(),
            b = upper_bound(x.begin(), x.end(), qb[i]) - x.begin() - 1;
        int ans = algo(a, b);
        printf("%d\n", ans);
    }
}