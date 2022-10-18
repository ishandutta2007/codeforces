#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

set<int> g[N],h[N];
vector<int> p;
bool used[N];

void dfs(int v)
{
    if(used[v])
        return;
    p.push_back(v);
    used[v]=true;
    for(int to:h[v])
        dfs(to);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            g[i].clear(),
            h[i].clear();
        map<array<int,3>,int> in;
        for(int i=1;i<=n-2;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            in[{a,b,c}]=i;
            in[{a,c,b}]=i;
            in[{b,a,c}]=i;
            in[{b,c,a}]=i;
            in[{c,a,b}]=i;
            in[{c,b,a}]=i;
            g[a].insert(b);
            g[a].insert(c);
            g[b].insert(a);
            g[b].insert(c);
            g[c].insert(a);
            g[c].insert(b);
        }
        set<pair<int,int>> vs;
        for(int i=1;i<=n;i++)
            vs.insert({g[i].size(),i});
        vector<int> q;
        set<pair<int,int>> edges;
        while(vs.size()>=3)
        {
            int v=vs.begin()->second;
            vs.erase(vs.begin());
            int x=*g[v].begin(),
                y=*next(g[v].begin());
//            cout<<v<<" : "<<x<<" "<<y<<"\n";
            q.push_back(in[{v,x,y}]);
            g[v].clear();
            vs.erase({g[x].size(),x});
            g[x].erase(v);
            vs.insert({g[x].size(),x});
            vs.erase({g[y].size(),y});
            g[y].erase(v);
            vs.insert({g[y].size(),y});
            if(!edges.count({v,x}))
                h[v].insert(x),
                h[x].insert(v);
            if(!edges.count({v,y}))
                h[v].insert(y),
                h[y].insert(v);
            edges.insert({x,y});
            edges.insert({y,x});
        }
        p.clear();
        for(int i=1;i<=n;i++)
            used[i]=false;
        for(int i=1;i<=n&&p.empty();i++)
            if(h[i].size()==1)
                dfs(i);
        if(p.empty())
            dfs(1);
        for(int e:p)
            cout<<e<<" ";
        cout<<"\n";
        for(int e:q)
            cout<<e<<" ";
        cout<<"\n";
    }
}