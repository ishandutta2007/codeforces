#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<P> G[MAXN];
bool centroid[MAXN];
int sz[MAXN],deep[MAXN],d[MAXN];
int ans;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<P> vec[2];
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F;
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void dfs(int v,int p,int cost,int last,int turns,int type)//enumerate path
{
    vec[type].push_back(P(turns,cost));
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F,c=G[v][i].S;
        if(to==p||centroid[to]) continue;
        int ncost=cost;
        add(ncost,a[to]);
        dfs(to,v,ncost,c,turns+(last^c),type);
    }
}
int calc(int addcost)
{
    int s0=0,s1=0;
    for(auto p:vec[0]) add(s0,p.S);
    for(auto p:vec[1]) add(s1,p.S);
    sort(vec[0].begin(),vec[0].end());
    sort(vec[1].begin(),vec[1].end());
    int res=0;
    int l=0,r=(int)vec[0].size()-1,sum=s0;
    while(l<r)
    {
        if(vec[0][l].F+vec[0][r].F<=k)
        {
            add(res,1LL*(r-l)*vec[0][l].S%MOD); add(res,1LL*(r-l)*addcost%MOD);
            dec(sum,vec[0][l].S); add(res,sum);
            l++; 
        }
        else
        {
            dec(sum,vec[0][r].S);
            r--;
        }
    }
    l=0,r=(int)vec[1].size()-1,sum=s1;
    while(l<r)
    {
        if(vec[1][l].F+vec[1][r].F<=k)
        {
            add(res,1LL*(r-l)*vec[1][l].S%MOD); add(res,1LL*(r-l)*addcost%MOD);
            dec(sum,vec[1][l].S); add(res,sum);
            l++; 
        }
        else
        {
            dec(sum,vec[1][r].S);
            r--;
        }
    }
    l=0,r=(int)vec[1].size()-1,sum=s1;
    while(l<(int)vec[0].size()&&r>=0)
    {
        if(vec[0][l].F+vec[1][r].F<=k-1)
        {
            add(res,sum); add(res,1LL*(r+1)*vec[0][l].S%MOD); add(res,1LL*(r+1)*addcost%MOD);
            l++; 
        }
        else
        {
            dec(sum,vec[1][r].S);
            r--;
        }
    }
    return res;
}
void solve(int v)
{
    centroid[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F;
        if(centroid[to]) continue;
        vec[0].clear(); vec[1].clear();
        dfs(to,v,a[to],G[v][i].S,0,G[v][i].S);
        dec(ans,calc(a[v]));
    }
    vec[0].clear(); vec[1].clear();
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F;
        if(centroid[to]) continue;
        dfs(to,v,a[to],G[v][i].S,0,G[v][i].S);
    }
    for(auto p:vec[0]) if(p.F<=k) {add(ans,p.S); add(ans,a[v]);}
    for(auto p:vec[1]) if(p.F<=k) {add(ans,p.S); add(ans,a[v]);}
    add(ans,calc(a[v]));
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F;
        if(centroid[to]) continue;
        int rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
void ac()
{
    ans=0;
    int rt=getroot(1,0,n).S;
    solve(rt);
    for(int i=1;i<=n;i++) add(ans,a[i]);
    printf("%d\n",ans);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(P(v,w)); G[v].push_back(P(u,w));
    }
    ac();
    return 0;
}