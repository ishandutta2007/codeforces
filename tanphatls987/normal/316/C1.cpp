#include <bits/stdc++.h>

using namespace std;



typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,int> lli;

#define X first
#define Y second

const ll linf=1e12;
const int inf=1e9+10;
const int N=6500,M=3e4+10;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

set <ii> pq;
template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
struct graph{
    int n,m,st,en;

    int v[M][2],cost[M][2],cap[M];
    int flow[M][2];
    vector <int> e[N];

    int d[N],g[N];
    int cf[N],t[N];
    void make_edge(int x,int y,int _cap,int _cost){
        ++m;
        v[m][0]=x;v[m][1]=y;
        e[x].push_back(m);
        e[y].push_back(m);
        flow[m][0]=0;
        flow[m][1]=cap[m]=_cap;
        cost[m][0]=_cost;
        cost[m][1]=-_cost;
    }

    bool dijkstra(){
        fill(d+1,d+n+1,inf);
        d[st]=0;
        cf[st]=inf;
        for(int i=1;i<=n;i++) pq.insert(ii(d[i],i));
        while (!pq.empty()){
            ii cur=*pq.begin();
            pq.erase(cur);
            for(auto i:e[cur.Y]){
                int dir=cur.Y==v[i][1];
                if (flow[i][dir]==cap[i]) continue;
                int y=v[i][dir^1];
                int eswei=d[cur.Y]+g[cur.Y]-g[y]+cost[i][dir];
                if (d[y]>eswei){
                    pq.erase(ii(d[y],y));
                    d[y]=eswei;
                    pq.insert(ii(d[y],y));
                    t[y]=i;
                    cf[y]=min(cf[cur.Y],cap[i]-flow[i][dir]);
                }
            }
        }
//        for(int i=1;i<=n;i++) cout<<d[i]<<" \n"[i==n];
//        for(int i=1;i<=n;i++) cout<<t[i]<<" \n"[i==n];
//        for(int i=1;i<=n;i++) cout<<cf[i]<<" \n"[i==n];
        return d[en]<inf;
    }
    int inc_flow(){
        int ans=cf[en]*(d[en]-g[st]+g[en]);
        int cur=en;
        while (cur!=st){
            int use=t[cur];
            int dir=cur==v[use][0];
            flow[use][dir]+=cf[en];
            flow[use][dir^1]-=cf[en];
            cur=v[use][dir];
        }
        for(int i=1;i<=n;i++) g[i]+=d[i];
        return ans;
    }
    int answer(){
//        cout<<st<<" "<<en<<" "<<n<<" "<<m<<'\n';
        int ans=0;
        while (dijkstra())
            ans+=inc_flow();
        return ans;
    }
}mygr;
int n,m,a[100][100];
bool check(int i,int j){
    return i>=0&&i<n&&j>=0&&j<m;
}
void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",a[i]+j);
    mygr.n=n*m+2;
    mygr.st=n*m+1;
    mygr.en=n*m+2;
    for(int i=0;i<n;i++)
        for(int j=i&1;j<m;j+=2){
            mygr.make_edge(mygr.st,i*m+j+1,1,0);
            for(int dir=0;dir<4;dir++){
                int ni=i+dx[dir],nj=j+dy[dir];
                if (check(ni,nj)) mygr.make_edge(i*m+j+1,ni*m+nj+1,1,a[i][j]!=a[ni][nj]);
            }
        }
    for(int i=0;i<n;i++)
        for(int j=(i&1)^1;j<m;j+=2)
            mygr.make_edge(i*m+j+1,mygr.en,1,0);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<mygr.answer();
}