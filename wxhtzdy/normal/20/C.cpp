#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long

const int mxN = 1e5+10;

int n, m;
int a, b, w;
int u;
vector<pair<int, int>> graf[mxN];
set<pair<int, int>> s;
bool mark[mxN];
int dist[mxN];
vector<int> path;

void setup()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        graf[a].push_back(make_pair(b, w));
        graf[b].push_back(make_pair(a, w));
    }
    for(int i = 2; i <= n; i++)
        dist[i] = 1e16;
}

void dfs(int root)
{
    for(int i = 0; i < graf[root].size(); i++)
    {
        int cvor = graf[root][i].F;
        if(dist[root]-dist[cvor] == graf[root][i].S)
        {
            dfs(cvor);
            path.push_back(cvor);
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    setup();
    s.insert(make_pair(0, 1));
    while(!s.empty())
    {
        u = (*s.begin()).S;
        s.erase(s.begin());
        /*if(mark[u]) continue;
        mark[u] = true;*/
        for(int i = 0; i < graf[u].size(); i++)
        {
            if (dist[graf[u][i].F] > dist[u] + graf[u][i].S) {
                s.erase({dist[graf[u][i].F], graf[u][i].F});
                dist[graf[u][i].F] = min(dist[graf[u][i].F], dist[u]+graf[u][i].S);
                s.insert(make_pair(dist[graf[u][i].F], graf[u][i].F));
            }
        }
    }
    if(dist[n] == 1e16)
    {
        cout << -1;
        return 0;
    }
    /*if (m == 9996) {
        cout << dist[n] << endl;
    }*/
    dfs(n);
    path.push_back(n);
    for(int node : path)
        cout << node << ' ';
    return 0;
}