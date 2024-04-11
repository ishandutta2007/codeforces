#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
#define int ll
const int maxn = 1005;
const int maxm = 30005;
struct Dinic
{
    struct edge
    {
        int to,next,cap,flow;
    }es[maxm];
    int d[maxn],cur[maxn],s,t,n;
    int head[maxn],tol;
    queue<int>q;
    void init(){memset(head,-1,sizeof(head));tol=0;}
    inline void adde(int u,int v,int w)
    {
//        cout<<"adde"<<u<<" "<<v<<" "<<w<<endl;
        es[tol].to=v;es[tol].cap=w;es[tol].flow=0;
        es[tol].next=head[u];head[u]=tol++;
        es[tol].to=u;es[tol].cap=es[tol].flow=0;
        es[tol].next=head[v];head[v]=tol++;
    }
    bool bfs()
    {
        for(int i=0;i<=n;i++){
            d[i]=-1;
        }
        d[s]=0;
        q.push(s);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=head[u];i!=-1;i=es[i].next){
                int v=es[i].to;
                if(d[v]==-1&&es[i].cap>es[i].flow){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int u,int low)
    {
        if(u==t||!low) return low;
        int f=0;
        for(int &i=cur[u];i!=-1;i=es[i].next){
            int v=es[i].to,tmp=0;
            if(d[u]+1==d[v]&&(tmp=dfs(v,min(low,es[i].cap-es[i].flow)))){
                es[i].flow+=tmp;
                es[i^1].flow-=tmp;
                f+=tmp;
                low-=tmp;
                if(!low) break;
            }
        }
        return f;
    }
    int Maxflow(int s,int t,int n)
    {
        this->s=s,this->t=t,this->n=n;
        int ans=0;
        while(bfs()){
            for(int i=0;i<n;i++) cur[i]=head[i];
            ans+=dfs(s,1e9);
        }
        return ans;
    }
};
int g[105][105];
vector<int> vx,vy;
int x1[55],yy1[55],x2[55],yy2[55];

int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ij
    {
        cin>>x1[i]>>yy1[i]>>x2[i]>>yy2[i];
        x1[i]--,yy1[i]--;
        vx.push_back(x1[i]),vx.push_back(x2[i]);
        vy.push_back(yy1[i]),vy.push_back(yy2[i]);
    }
    sort(all(vx)),sort(all(vy));
    int nx=unique(all(vx))-vx.begin(),ny=unique(all(vy))-vy.begin();
    ij
    {
        x1[i]=lower_bound(vx.begin(),vx.begin()+nx,x1[i])-vx.begin()+1;
        x2[i]=lower_bound(vx.begin(),vx.begin()+nx,x2[i])-vx.begin()+1;
        yy1[i]=lower_bound(vy.begin(),vy.begin()+ny,yy1[i])-vy.begin()+1;
        yy2[i]=lower_bound(vy.begin(),vy.begin()+ny,yy2[i])-vy.begin()+1;
        for(int x=x1[i];x<x2[i];++x)
            for(int y=yy1[i];y<yy2[i];++y)
                g[x][y]=1;
//        cout<<x1[i]<<" "<<yy1[i]<<" "<<x2[i]<<" "<<yy2[i]<<endl;
    }
    Dinic d;
    d.init();
    int s=nx+ny+1,t=nx+ny+2;
//    cout<<nx<<" "<<ny<<endl;
//    for(int i=0;i<nx;++i) cout<<vx[i]<<" ";cout<<endl;
//    for(int i=0;i<ny;++i) cout<<vy[i]<<" ";cout<<endl;
    for(int i=1;i<nx;++i) d.adde(s,i,vx[i]-vx[i-1]);
    for(int i=1;i<ny;++i) d.adde(i+nx,t,vy[i]-vy[i-1]);
//    for(int i=1;i<=nx;++i) {
//        for(int j=1;j<=ny;++j)
//            cout<<g[i][j]<<" ";cout<<endl;}
    for(int i=1;i<nx;++i)
        for(int j=1;j<ny;++j)
        {
            if(g[i][j]) d.adde(i,nx+j,1e9);
        }
    cout<<d.Maxflow(s, t, t)<<endl;
}

/*
 4 1
 1 1 4 4
*/