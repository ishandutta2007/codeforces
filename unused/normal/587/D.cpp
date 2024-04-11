#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
vector<int> graph[MAXN];
int up[MAXN], visit[MAXN], vtime;
vector<int> stk;
int scc_idx[MAXN], scc_cnt;
int scc_n;
void dfs(int nod) {
    up[nod] = visit[nod] = ++vtime;
    stk.push_back(nod);
    for (int next : graph[nod]) {
        if (visit[next] == 0) {
            dfs(next);
            up[nod] = min(up[nod], up[next]);
        }
        else if (scc_idx[next] == 0)
            up[nod] = min(up[nod], visit[next]);
    }
    if (up[nod] == visit[nod]) {
        ++scc_cnt;
        int t;
        do {
            t = stk.back();
            stk.pop_back();
            scc_idx[t] = scc_cnt;
        } while (!stk.empty() && t != nod);
    }
}
// find SCCs in given directed graph
// O(V+E)
void get_scc() {
    vtime = 0;
    memset(visit, 0, sizeof(visit[0]) * scc_n);
    scc_cnt = 0;
    memset(scc_idx, 0, sizeof(scc_idx[0]) * scc_n);
    for (int i = 0; i < scc_n; ++i)
        if (visit[i] == 0) dfs(i);
}

struct edge
{
    int s,e,c,t;
};

edge dat[50005];
map<int, vector<int>> edges[50005];
pair<int, int> tp[50005];
vector<int> target;
vector<int> tgs[50005];
int n, m;

void make_negative(const vector<int> &vt)
{
    int size = 1;
    while (size < vt.size()) size *= 2;
    vector<int> dat(size * 2);
    for (int i = 0; i < size; i++)
    {
        if (i >= vt.size()) dat[i + size] = -1;
        else dat[i + size] = vt[i] + target.size();
    }
    for (int i = size - 1; i >= 1; i--)
    {
        if (dat[i<<1] == -1 && dat[i<<1|1] == -1) dat[i] = -1;
        else
        {
            dat[i] = scc_n++;
            graph[dat[i]].clear();
            if (dat[i<<1] != -1) graph[dat[i]].push_back(dat[i<<1]);
            if (dat[i<<1|1] != -1) graph[dat[i]].push_back(dat[i<<1|1]);
        }
    }

    for (int i = 0; i < vt.size(); i++)
    {
        int ll = size, rr = size + i - 1;
        while (ll <= rr)
        {
            if (ll & 1)
            {
                if (dat[ll] != -1) graph[vt[i]].push_back(dat[ll]);
                ++ll;
            }
            if (!(rr & 1))
            {
                if (dat[rr] != -1) graph[vt[i]].push_back(dat[rr]);
                --rr;
            }
            ll >>= 1; rr >>= 1;
        }

        ll = size + i + 1, rr = size + vt.size() - 1;
        while (ll <= rr)
        {
            if (ll & 1)
            {
                if (dat[ll] != -1) graph[vt[i]].push_back(dat[ll]);
                ++ll;
            }
            if (!(rr & 1))
            {
                if (dat[rr] != -1) graph[vt[i]].push_back(dat[rr]);
                --rr;
            }
            ll >>= 1; rr >>= 1;
        }
    }
}

bool check(int mid, bool print = false)
{
    for (int i = 0; i < target.size(); i++)
    {
        if (dat[target[i]].t > mid)
        {
            graph[i].push_back(i + target.size());
        }
    }

    get_scc();

    for (int i = 0; i < target.size(); i++)
    {
        if (dat[target[i]].t > mid)
        {
            graph[i].pop_back();
        }
    }


    for (int i = 0; i < target.size(); i++)
    {
        if (scc_idx[i] == scc_idx[i + target.size()]) return false;
    }

    if (!print) return true;

    vector<int> ans;

    for (int i = 0; i < target.size(); i++)
    {
        if (scc_idx[i] < scc_idx[i + target.size()]) ans.push_back(target[i] + 1);
    }

    printf("Yes\n%d %zd\n", mid, ans.size());
    for (int t : ans) printf("%d ", t);
    printf("\n");

    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        dat[i] = {a, b, c, d};

        auto &vt = edges[a][c];
        vt.push_back(i);
        if (vt.size() > 2)
        {
            printf("No\n");
            return 0;
        }

        auto &vt2 = edges[b][c];
        vt2.push_back(i);
        if (vt2.size() > 2)
        {
            printf("No\n");
            return 0;
        }

    }

    for (int i = 1; i <= n; i++)
    {
        tp[i] = {-1, -1};
        for (auto &&e : edges[i])
        {
            if (e.second.size() == 2)
            {
                if (tp[i].first != -1)
                {
                    printf("No\n");
                    return 0;
                }
                target.push_back(e.second[0]);
                target.push_back(e.second[1]);
                tp[i] = {e.second[0], e.second[1]};
            }
        }
    }

    sort(target.begin(), target.end());
    target.erase(unique(target.begin(), target.end()), target.end());

    scc_n = target.size() * 2;

    for (int i = 1; i <= n; i++)
    {
        if (tp[i].first == -1) continue;

        int a = lower_bound(target.begin(), target.end(), tp[i].first) - target.begin();
        int b = lower_bound(target.begin(), target.end(), tp[i].second) - target.begin();
        graph[a + target.size()].push_back(b);
        graph[b + target.size()].push_back(a);
    }

    for (int i = 0; i < target.size(); i++)
    {
        tgs[dat[target[i]].s].push_back(i);
        tgs[dat[target[i]].e].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (tgs[i].size() <= 1) continue;
        make_negative(tgs[i]);
    }

    int lo = 0, hi = 1e9, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    if (ans == -1) printf("No\n");
    else
    {
        check(ans, true);
    }
}