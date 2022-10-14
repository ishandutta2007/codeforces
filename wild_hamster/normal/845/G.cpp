#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,w,path_w,m;
vector<pii> g[100500];
vector<ll> cycles;
ll d[100500], used[100500];
string s;
void dfs(ll v)
{
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i].X;
        ll val = g[v][i].Y;
        if (!used[to])
        {
            d[to] = (d[v]^val);
            dfs(to);
        } else
        {
            ll tmp = (d[v]^d[to]^val);
            if (tmp != 0)
                cycles.push_back(tmp);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        g[x].push_back(mp(y,w));
        g[y].push_back(mp(x,w));
    }
    dfs(1);
    ll sz = cycles.size();
    cycles.push_back(d[n]);
    ll cur_row = 0;
    for (int j = 28; j >= 0; j--)
    {
        int idx = -1;
        for (int i = cur_row; i < sz; i++)
            if ((cycles[i]&(1<<j)) != 0)
            {
                idx = i;
                break;
            }
        if (idx == -1)
            continue;
        else
        {
            swap(cycles[idx], cycles[cur_row]);
            for (i = cur_row+1; i <= sz; i++)
            {
                if ((cycles[i]&(1<<j)) != 0)
                {
                    cycles[i] ^= cycles[cur_row];
                }
            }
            cur_row++;
        }
    }
    cout << cycles.back() << endl;
    return 0;
}