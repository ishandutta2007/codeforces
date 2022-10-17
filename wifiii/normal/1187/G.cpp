#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)
const int maxn = 600005;
namespace mincost
{
    struct edge
    {
        int to,nxt,cc,ff,cost;
    }es[maxn<<1];
    int pre[maxn],d[maxn],n,head[maxn],tot=2;
    bool vis[maxn];
    inline void adde(int u,int v,int w,int c)
    {
        es[tot]=edge{v,head[u],w,0,c};head[u]=tot++;
        es[tot]=edge{u,head[v],0,0,-c};head[v]=tot++;
    }
    queue<int> Q;
    void init() {memset(head,0,sizeof(head));tot=2;}
    bool spfa(int s,int t)
    {
        for(int i=0;i<=n;i++) vis[i]=0,pre[i]=0,d[i]=1e9;
        d[s]=0;
        Q.push(s);
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            vis[u]=0;
            for(int i=head[u];i;i=es[i].nxt){
                int v=es[i].to;
                if(es[i].cc>es[i].ff&&d[v]>d[u]+es[i].cost){
                    d[v]=d[u]+es[i].cost;
                    pre[v]=i;
                    if(!vis[v]){
                        vis[v]=1;
                        Q.push(v);
                    }
                }
            }
        }
        return pre[t];
    }
    int Maxff(int s,int t,int n,int &cost)
    {
        mincost::n = n;
        int ans=0;
        while(spfa(s,t)){
            int mn=1e9;
            for(int i=pre[t];i;i=pre[es[i^1].to]){
                if(mn>es[i].cc-es[i].ff){
                    mn=es[i].cc-es[i].ff;
                }
            }
            for(int i=pre[t];i;i=pre[es[i^1].to]) es[i].ff+=mn, es[i^1].ff-=mn;
            ans+=mn,cost+=mn*d[t];
        }
        return ans;
    }
};


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k,c,d;
    cin>>n>>m>>k>>c>>d;
    mincost::init();
    int s=(n+k+1)*n+1,t=s+1;
    for(int i=1;i<=k;++i)
    {
        int x;cin>>x;
        mincost::adde(s,x,1,0);
    }
    for(int i=0;i<=n+k;++i) mincost::adde(1+i*n,t,k,i*c); //n+m+1 layers
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        for(int i=0;i<n+k;++i)
            for(int j=0;j<k;++j)
                mincost::adde(x+i*n,y+i*n+n,1,d*(2*j+1)); //layer i -> layer i+1
        for(int i=0;i<n+k;++i)
            for(int j=0;j<k;++j)
                mincost::adde(y+i*n,x+i*n+n,1,d*(2*j+1));
    }
    for(int i=1;i<=(n+k)*n;++i)
            mincost::adde(i,i+n,k,0);
    int ans=0;
    mincost::Maxff(s, t, t, ans);
    cout<<ans<<endl;
}