#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

int ans[105];
const int maxn = 1005;
const int maxm = 100005;
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
        es[tol] = {v,head[u],w,0}; head[u] = tol++;
        es[tol] = {u,head[v],0,0}; head[v] = tol++;
    }
    bool bfs()
    {
        for(int i=0;i<=n;i++)d[i]=-1;
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
    int maxflow(int s,int t,int n)
    {
        this->s=s,this->t=t,this->n=n;
        int ans=0;
        while(bfs()){
            for(int i=0;i<n;i++) cur[i]=head[i];
            ans+=dfs(s,1e9);
        }
        return ans;
    }
}dinic;
int L[105],R[105];
int main() {
    dinic.init();
    int n,m;
    cin>>n>>m;
    int ok=1,tot=0,S=m+n+1,T=S+1;
    for(int i=1;i<=n;++i) dinic.adde(i+m,T,1);
    for(int i=1;i<=m;++i) {
        int l,r,c;
        cin>>l>>r>>c;
        L[i]=l,R[i]=r-1;
        tot+=c; // total flow
        if(ans[r]) {
            ok=0;
            break;
        }
        ans[r]=m+1;
        dinic.adde(S,i,c);
    }
    for(int i=1;i<=m;++i) {
        int l=L[i],r=R[i];
        // [l,r]
        // i -> i+m : c
        // i+m -> [l,r] : 1
        for(int j=l;j<=r;++j) if(!ans[j]) dinic.adde(i,m+j,1);
    }
    if(!ok) return cout<<-1<<endl,0;
    int flow=dinic.maxflow(S,T,T);
    if(flow!=tot) return cout<<-1<<endl,0;
    for(int i=1;i<=m;++i) {
        // every edges from ith exam
        for(int j=dinic.head[i];~j;j=dinic.es[j].next) {
            if(dinic.es[j].flow) {
                ans[dinic.es[j].to-m]=i;
            }
        }
    }
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;
}