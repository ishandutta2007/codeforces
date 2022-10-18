#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<pii> g[N];
bool used[N];
int val[N];

void dfs(int v,int cur)
{
    if(used[v])
        return;
    used[v]=true;
    val[v]=cur;
    for(auto to:g[v])
        dfs(to.x,cur^to.y);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    dfs(1,0);
    set<int,greater<int>> basis;
    for(int i=1;i<=n;i++)
        for(auto to:g[i])
        {
            int x=val[i]^val[to.x]^to.y;
            for(int y:basis)
                if((x^y)<x)
                    x^=y;
            if(x)
                basis.insert(x);
        }
    int x=val[n];
    for(int y:basis)
        if((x^y)<x)
            x^=y;
    cout<<x;
}