#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=305;
vector <int> a[maxn];
vector <int> b[maxn];
int curflow=0;
int d[maxn];
int ptr[maxn];
int curw=1e18;
int g[maxn][maxn];
int sz;
int c[maxn];
bool used[maxn];
int mt[maxn];
vector <int> z[maxn];
bool kun(int x)
{
    //cout<<x<<" x "<<endl;
     used[x]=true;
     for(auto v:a[x])
     {
         //cout<<v<<" v1 "<<x<<" x1 "<<endl;
         {
             //cout<<v<<" v "<<mt[v]<<" mt[v] "<<endl;
             if(mt[v]==(-1) || (!used[mt[v]] && kun(mt[v])))
             {
                 //cout<<v<<" v "<<x<<" x "<<endl;
                 mt[v]=x;
                 return true;
             }
         }
     }
     return false;
}
bool bfs()
{
    queue<int> q;q.push(0);used[0]=true;d[0]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=0;i<sz;++i)
        {
            if(!used[i] && g[x][i]>=curw)
            {
                used[i]=true;d[i]=d[x]+1;q.push(i);
            }
        }
    }
    return used[sz-1];
}
bool dfs(int x)
{
    //cout<<x<<" x "<<endl;
    if(x==(sz-1)) {curflow+=curw;return true;}
    for(int i=ptr[x];i<sz;++i)
    {
        ++ptr[x];
        if(d[i]==(d[x]+1) && g[x][i]>=curw)
        {
            if(dfs(i))
            {
                g[x][i]-=curw;g[i][x]+=curw;
                return true;
            }
        }
    }
    return false;
}
int dinic()
{
    while(curw>0)
    {
        //cout<<curw<<" curw "<<endl;
    while(bfs())
    {
        //cout<<" tgrfed "<<endl;
        fill(used,used+maxn,false);
        fill(ptr,ptr+maxn,0);
        bool val=dfs(0);
        assert(val);
        fill(used,used+maxn,false);
    }
    fill(used,used+maxn,false);
    curw/=2;
    }
    return curflow;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {int c;cin>>c;vector <int> v(c);for(auto &h:v) {cin>>h;--h;}a[i]=v;}
    for(int i=0;i<n;++i) cin>>c[i];
    fill(mt,mt+n,-1);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
        fill(used,used+n,false);
        kun(i);
    }
    //for(int i=0;i<n;++i) cerr<<i<<" i "<<mt[i]<<" mt[i] "<<endl;
    for(int i=0;i<n;++i)
    {
        for(auto v:a[i])
        {
            int o=mt[v];
            if(o!=i) b[i].push_back(o);
        }
    }
    sz=(n+2);
    int ans=0;
    for(int i=0;i<n;++i) if(c[i]<0) ans+=c[i];
    for(int i=0;i<n;++i) for(auto v:b[i]) g[i+1][v+1]=1e15;
    for(int i=0;i<n;++i) {if(c[i]<0) g[0][i+1]=(-c[i]); else g[i+1][n+1]=c[i];}
    //for(int i=0;i<sz;++i) for(int j=0;j<sz;++j) cout<<i<<" i "<<j<<" j "<<g[i][j]<<" g "<<endl;
    ans+=dinic();
    cout<<ans;
    return 0;
}