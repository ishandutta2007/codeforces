#include <bits/stdc++.h>
using namespace std;

int parent[500005];
int rnk[500005];

struct change
{
    int *arr;
    int idx;
    int val;
};

vector<change> vt;

int getparent(int t)
{
    return t == parent[t] ? t : getparent(parent[t]);
}

bool merge(int a, int b)
{
    a = getparent(a); b = getparent(b);
    if (a == b) return false;

    if (rnk[a] < rnk[b]) swap(a, b);
    else if (rnk[a] == rnk[b])
    {
        vt.push_back({rnk, a, rnk[a]++});
    }
    vt.push_back({parent, b, parent[b]});
    parent[b] = a;

    return true;
}

void rollback(int t)
{
    while (vt.size() > t)
    {
        auto &c = vt.back();
        c.arr[c.idx] = c.val;
        vt.pop_back();
    }
}

struct edge
{
    int s, e, v;
    bool operator<(const edge &rhs) const
    {
        return v < rhs.v;
    }
};

edge dat[500005];
map<int, vector<tuple<int, int, int>>> mp;
bool NO[500005];

int main()
{
    int n, m; scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &dat[i].s, &dat[i].e, &dat[i].v);
    }

    for (int i = 1; i <= n; i++) parent[i] = i;

    int q;
    scanf("%d",&q);

    for (int i = 0; i < q; i++)
    {
        int k;
        scanf("%d",&k);
        for (int j = 0; j < k; j++)
        {
            int idx;
            scanf("%d",&idx);
            --idx;
            mp[dat[idx].v].emplace_back(i, dat[idx].s, dat[idx].e);
        }
    }

    sort(dat, dat + m);

    int p = 0;
    for (auto &e : mp)
    {
        while (p < m && dat[p].v < e.first) merge(dat[p].s, dat[p].e), ++p;

        int last = vt.size();

        sort(e.second.begin(), e.second.end());

        int idx = -1;

        for (auto &f : e.second)
        {
            int x, y, z;
            tie(x, y, z) = f;

            if (idx != x)
            {
                rollback(last);
                idx = x;
            }

            if (merge(y, z) == false) NO[x] = true;
        }

        rollback(last);
    }

    for (int i = 0; i < q; i++)
    {
        if (NO[i]) printf("NO\n");
        else printf("YES\n");
    }
}