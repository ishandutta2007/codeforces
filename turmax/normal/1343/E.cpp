#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> bfs(vector <vector <int> > g,int x)
{
    int n=g.size();
    bool used[n];
    int is[n];
    deque <int> q;
    for(int i=0;i<n;++i)
    {
        used[i]=false;
        is[i]=1e18;
    }
    is[x]=0;
    used[x]=true;
    q.push_back(x);
    while(!q.empty())
    {
        deque <int> q1;
        while(!q.empty())
        {
            int curr=q.front();
            //cout<<curr<<" curr "<<endl;
            q.pop_front();
            for(int i=0;i<g[curr].size();++i)
            {
                int v=g[curr][i];
                if(!used[v])
                {
                    q1.push_back(v);
                    used[v]=true;
                    is[v]=is[curr]+1;
                }
            }
        }
        q=q1;
    }
    vector <int> res(n);
    for(int i=0;i<n;++i)
    {
        res[i]=is[i];
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    a--;b--;c--;
    vector <vector <int> > g(n);
    int p[m];
    for(int i=0;i<m;++i)
    {
        cin>>p[i];
    }
    sort(p,p+m);
    int pr[m+1];
    pr[0]=0;
    for(int i=0;i<m;++i)
    {
        pr[i+1]=pr[i]+p[i];
    }
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        g[x].push_back(y);g[y].push_back(x);
    }
    vector <int> va=bfs(g,a);vector <int> vb=bfs(g,b);vector <int> vc=bfs(g,c);
    int ans=1e18;
    for(int i=0;i<n;++i)
    {
        int x=va[i];
        int y=vb[i];
        int z=vc[i];
        if((x+y+z)<=m)
        ans=min(ans,pr[y]+pr[x+y+z]);
    }
    cout<<ans<<endl;
    }
    return 0;
}