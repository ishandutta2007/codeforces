#include <bits/stdc++.h>
using namespace std;

int n, m, qq;
int dat[11][100005];
constexpr int TSIZE = 131072;

struct uf
{
    vector<int> par;
    vector<int> rnk;
    int comp;
    int l, r;

    void init(int L, int R)
    {
        l = L; r = R; comp = (r - l + 1) * n;
        par.reserve(comp);
        rnk.resize(comp);
        for (int i = 0; i < comp; i++) par.push_back(i);
    }

    int fn(int t)
    {
        return par[t] == t ? t : par[t] = fn(par[t]);
    }

    bool mg(int a, int b)
    {
        a = fn(a); b = fn(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        else if (rnk[a] == rnk[b]) ++rnk[a];
        par[b] = a; --comp; return true;
    }
};

namespace guf
{
    pair<int, int> par[50][100005];
    int rnk[50][100005];
    int vis[50][100005];

    pair<int, int> fn(int x, int y)
    {
        if (vis[x][y] != qq)
        {
            vis[x][y] = qq;
            par[x][y] = {x, y};
            rnk[x][y] = 0;
        }
        return par[x][y] == make_pair(x, y) ? make_pair(x, y) : par[x][y] = fn(par[x][y].first, par[x][y].second);
    }

    bool mg(int a1, int a2, int b1, int b2)
    {
        auto a = fn(a1, a2), b = fn(b1, b2);
        if (a == b) return false;
        if (rnk[a.first][a.second] < rnk[b.first][b.second]) swap(a, b);
        else if (rnk[a.first][a.second] == rnk[b.first][b.second]) rnk[a.first][a.second]++;
        par[b.first][b.second] = a; return true;
    }
};

uf tree[TSIZE * 2];

constexpr int dr[4][2] =
{
    1,0,
    0,1,
    -1,0,
    0,-1
};

void recur(int t, int l, int r)
{
    tree[t].init(l, r);

    for (int i = 0; i < n; i++)
    {
        for (int j = l; j <= r; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int x = i + dr[k][0];
                int y = j + dr[k][1];

                if (x >= 0 && x < n && y >= l && y <= r && dat[i][j] == dat[x][y])
                {
                    tree[t].mg((j - l) * n + i, (y - l) * n + x);
                }
            }
        }
    }

    if (l < r)
    {
        int M = (l + r) / 2;
        recur(t << 1, l, M);
        recur(t << 1 | 1, M + 1, r);
    }
}

vector<int> vt;

void collect_idx(int t, int L, int R)
{
    int l = tree[t].l, r = tree[t].r;
    if (l > R || r < L) return;

    if (L <= l && r <= R)
    {
        vt.push_back(t);
        return;
    }

    collect_idx(t << 1, L, R);
    collect_idx(t << 1 | 1, L, R);
}

int process(int L, int R)
{
    vt.clear();
    collect_idx(1, L, R);

    int ans = 0;
    for (int t : vt) ans += tree[t].comp;

    for (int i = 1; i < vt.size(); i++)
    {
        auto &LT = tree[vt[i - 1]];
        auto &RT = tree[vt[i]];
        assert(LT.r + 1 == RT.l);

        for (int j = 0; j < n; j++)
        {
            if (dat[j][LT.r] != dat[j][RT.l]) continue;

            int d1 = LT.fn((LT.r - LT.l) * n + j);
            int d2 = RT.fn(j);

            if (guf::mg(i - 1, d1, i, d2)) --ans;
        }
    }

    return ans;
}

int main()
{
    int q;
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &dat[i][j]);
        }
    }

    recur(1, 0, m - 1);

    for (qq = 1; qq <= q; qq++)
    {
        int l, r;
        scanf("%d%d",&l,&r);
        --l; --r;
        printf("%d\n", process(l, r));
    }
}