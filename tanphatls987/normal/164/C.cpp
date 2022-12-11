#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e15;
const int MOD=1e9+7;
const int N=1e3+10,M=1e6+10;

int n,k,v[M][2],cap[M],flow[M][2],cost[M][2],t[N<<1],ti[N][2],p[N],h[N<<1],st,en;
ll d[N<<1],g[N<<1];
vector <int> e[N<<1];
bool comp(int x,int y){
    return ti[x][0]<ti[y][0];
}
template <class T>
T minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void set_edge(int x,int y,int _cap,int _cost){
    static int m=0;
    ++m;
    v[m][0]=x;v[m][1]=y;
    e[x].push_back(m);
    e[y].push_back(m);
    cap[m]=flow[m][1]=_cap;
    cost[m][0]=_cost;
    cost[m][1]=-cost[m][0];
//    printf("%d %d %d %d\n",x,y,_cap,_cost);
}
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n){
        int w;
        scanf("%d%d%d",ti[i],ti[i]+1,&w);
        ti[i][1]+=ti[i][0];
        set_edge(i,n+i,1,-w);
    }
    set_edge(2*n+1,2*n+2,k,0);
    FOR(i,1,n){
        set_edge(n+i,2*n+3,1,0);
        set_edge(2*n+2,i,1,0);
    }
    FOR(i,1,n)
        FOR(j,1,n) if (ti[i][1]<=ti[j][0]) set_edge(n+i,j,1,0);
    st=2*n+1;en=2*n+3;
}
void find_longest(){
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
    FOR(j,1,n){
        int x=p[j];
//        printf("%d %d\n",j,x);
        d[n+x]=d[x]+cost[x][0];
        for(auto i:e[n+x]) if (v[i][0]==n+x){
            int y=v[i][0]+v[i][1]-n-x;
            d[y]=min(d[y],d[n+x]);
        }
//        FOR(i,1,en) cout<<d[i]<<" \n"[i==en];
    }
    d[en]=*min_element(d+1,d+en);
}
bool BFS(){
    d[0]=inf;
    FOR(i,1,en){
        g[i]+=d[i];
        d[i]=inf;
    }
    d[st]=0;
    t[st]=-1;
    memset(h,0,sizeof(h));
    FOR(phase,1,en){
        int x=0;
        FOR(i,1,en) if (!h[i]&&d[i]<d[x]) x=i;
        h[x]=1;
        for(auto i:e[x]){
            int dir=x!=v[i][0],y=v[i][dir^1];
            if (flow[i][dir]==cap[i]) continue;
            ll nw=cost[i][dir]+g[x]-g[y];
            if (!h[y]&&minimize(d[y],d[x]+nw)) t[y]=i;
        }
    }
    return d[en]<inf;
}
void inc_flow(){
    int x=en;
    while (x!=st){
        int idx=t[x],dir=(x==v[idx][0]);
        flow[idx][dir]++;
        flow[idx][dir^1]--;
        x=v[idx][dir];
    }
}
void solve(){
    find_longest();
    while (BFS()) inc_flow();
    FOR(i,1,n) printf("%d ",flow[i][0]);
}
int main(){
    prepare();
    solve();
}