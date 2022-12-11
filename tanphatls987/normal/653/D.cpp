#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+10,M=1e3+10;

int n,m,k,rw[M];
queue <int> q;
struct max_flow{
    vector <int> e[N];
    int st,en,m,v[M][2],flow[M][2],cap[M];
    int t[N],f[N];
    void add_edge(int x,int y){
        ++m;
        v[m][0]=x;v[m][1]=y;
        e[x].push_back(m);
        e[y].push_back(m);
    }
    void build(int _st,int _en){
        st=_st;en=_en;
        m=0;
    }
    void reset(double mid){
        FOR(i,1,m) {
            if (k*mid<=rw[i]) cap[i]=k;
            else cap[i]=int(rw[i]/mid);
        }
//        FOR(i,1,m) cout<<v[i][0]<<" "<<v[i][1]<<" "<<cap[i]<<'\n';
        FOR(i,1,m) {
            flow[i][1]=cap[i];
            flow[i][0]=0;
        }
        f[st]=inf;
    }
    bool BFS(){
        memset(t,0,sizeof(t));
        t[st]=-1;
        q.push(st);
        while (!q.empty()){
            int x=q.front();q.pop();
            for(auto i:e[x]){
                int dir=x==v[i][1];
                if (flow[i][dir]==cap[i]) continue;
                int y=v[i][dir^1];
                if (t[y]) continue;
                t[y]=i;
                f[y]=min(f[x],cap[i]-flow[i][dir]);
                q.push(y);
            }
        }
        return t[en];
    }
    int inc_flow(){
        int cur=en;
        while (cur!=st){
            int idx=t[cur],dir=cur==v[idx][0];
            flow[idx][dir]+=f[en];
            flow[idx][dir^1]-=f[en];
            cur=v[idx][dir];
        }
        return f[en];
    }
    int answer(){
        int ans=0;
        while (BFS()) ans+=inc_flow();
//        cout<<ans<<'\n';
        return ans;
    }
}mygr;
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    mygr.build(1,n);
    FOR(i,1,m) {
        int x,y;
        scanf("%d%d%d",&x,&y,rw+i);
        mygr.add_edge(x,y);
    }
}
bool check(double mid){
    mygr.reset(mid);
    return mygr.answer()>=k;
}
double solve(){
    double L=0,R=inf;
//    cout<<check(0.5)<<'\n';
    FOR(pha,1,300){
        double mid=(L+R)/2;
        if (check(mid)) L=mid;
        else R=mid;
    }
    return R*k;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    printf("%.9f\n",solve());
}