#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=3e5+100;

set<int> g[N];
pair<set<int>,int> gv[N];
int eq[N];
int c[N];

int dfs(int v,int p,int mn)
{
    c[v]=mn;
    for(int to:g[v])
        if(p!=to)
            return dfs(to,v,mn+1);
    return mn;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        gv[i]={{i},i};
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        gv[u].first.insert(v);
        gv[v].first.insert(u);
    }
    sort(gv+1,gv+n+1);
    set<int> dif;
    for(int i=1,last=0;i<=n;i++)
    {
        if(i==1||gv[i].first!=gv[i-1].first)
            last=gv[i].second,
            dif.insert(gv[i].second);
        else
            for(int to:gv[i].first)
                g[to].erase(gv[i].second);
        eq[gv[i].second]=last;
    }

//    cout<<"dif: ";
//    for(int x:dif)
//        cout<<x<<" ";
//    cout<<"\n";
//
//    cout<<"eq: ";
//    for(int i=1;i<=n;i++)
//        cout<<eq[i]<<" ";
//    cout<<"\n";

    for(int v:dif)
        if(g[v].size()>2)
            cout<<"NO",exit(0);
    int mx=0;
    for(int v:dif)
        if(g[v].size()<=1&&!c[v])
            mx=dfs(v,0,mx+1);

    for(int v:dif)
        if(!c[v])
            cout<<"NO",exit(0);

    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<c[eq[i]]<<" ";
}