#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

namespace small
{
    const int N=1010;

    int g[N][N];

    int dsu[N];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            dsu[i]=i;
    }
    int get(int i)
    {
        return i==dsu[i]?i:dsu[i]=get(dsu[i]);
    }
    bool un(int i,int j)
    {
        i=get(i);
        j=get(j);
        if(i==j)
            return false;
        if(rand()&1)
            swap(i,j);
        dsu[i]=j;
        return true;
    }

    vector<pair<int,pii>> edges;
    int calc(int n,int i,int j,int x)
    {
        init(n);
        int res=0;
        bool tried=false;
        for(auto[w,p]:edges)
        {
            if(w>=x&&!tried)
            {
                if(un(i,j))
                    res+=x;
                tried=true;
            }
            if(p!=pair(i,j)&&un(p.x,p.y))
                res+=w;
        }
        return res;
    }

    int solve(int n,int m)
    {
        int x=0;
        for(int _=1;_<=m;_++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u][v]=g[v][u]=w;
            x^=w;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                edges.push_back({g[i][j],{i,j}});
        sort(edges.begin(),edges.end());
        int ans=1e18;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!g[i][j])
                    ans=min(ans,calc(n,i,j,x));
        return ans;
    }
}

namespace large
{
    const int N=2e5+100;

    vector<int> g[N];

    int dsu[N];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            dsu[i]=i;
    }
    int get(int i)
    {
        return i==dsu[i]?i:dsu[i]=get(dsu[i]);
    }
    bool un(int i,int j)
    {
        i=get(i);
        j=get(j);
        if(i==j)
            return false;
        if(rand()&1)
            swap(i,j);
        dsu[i]=j;
        return true;
    }

    int calc(int n)
    {
        vector<pair<int,pii>> edges;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                edges.push_back({g[i][j],{i,j}});
        sort(edges.begin(),edges.end());
        init(n);
        int res=0;
        for(auto[w,p]:edges)
            if(un(p.x,p.y))
                res+=w;
        return res;
    }

    int solve(int n,int m)
    {
        vector<pair<int,pii>> edges;
        for(int _=1;_<=m;_++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({w,{u,v}});
            g[u].push_back(v);
            g[v].push_back(u);
        }
        set<int> comps;
        for(int i=1;i<=n;i++)
            comps.insert(i);
        init(n);
        for(int i=1;i<=n;i++)
        {
            set<int> s;
            for(int j:g[i])
                s.insert(get(j));
            for(int j:comps)
                if(!s.count(j))
                    un(get(i),j);
            for(auto it=comps.begin();it!=comps.end();)
                if(get(*it)==*it)
                    it++;
                else
                    comps.erase(it++);
        }
        sort(edges.begin(),edges.end());
        int res=0;
        for(auto[w,p]:edges)
            if(un(p.x,p.y))
                res+=w;
        return res;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    if(n*(n-1)/2-m<=n-1)
        cout<<small::solve(n,m);
    else
        cout<<large::solve(n,m);
}