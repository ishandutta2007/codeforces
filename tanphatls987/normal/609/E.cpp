#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=2e5+10;

priority_queue <ii> q;
vector <int> e[N];
int n,m,p[N][20],w[N],v[N][2],d[N],lv[N],he[N][20];
bool minimize(int &x,int y){
    if (x>y) x=y;else return 0;
    return 1;
}
void prepare(){
    scanf("%d%d",&n,&m);
    int x,y;
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,w+i);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
}
ll prim(){
    fill(d+2,d+n+1,inf);
    v[0][1]=1;
    q.push(ii(0,1));
    ll ans=0;
    while (!q.empty()){
        ii cur=q.top();q.pop();
        if (-cur.X>d[cur.Y]) continue;
        ans+=d[cur.Y];
        int lidx=p[cur.Y][0],pa=v[lidx][0]+v[lidx][1]-cur.Y;
        lv[cur.Y]=lv[pa]+1;
        he[cur.Y][0]=w[lidx];
        p[cur.Y][0]=pa;
        for(auto i:e[cur.Y]){
            int nx=v[i][0]+v[i][1]-cur.Y;
            if (minimize(d[nx],w[i])) {
                p[nx][0]=i;
                q.push(ii(-d[nx],nx));
            }
        }
        d[cur.Y]=-1;
    }
    return ans;
}
int query(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    int ans=0;
    for(int i=0,v=lv[x]-lv[y];v;i++,v>>=1) if (v&1) {
        ans=max(ans,he[x][i]);
        x=p[x][i];
    }
    if (x==y) return ans;
    FORD(i,int(log2(lv[x])),0) if (p[x][i]!=p[y][i]){
        ans=max(ans,max(he[x][i],he[y][i]));
        x=p[x][i],y=p[y][i];
    }
    return max(ans,max(he[x][0],he[y][0]));
}
void solve(){
    ll best=prim();
    ///precalc
    FOR(lay,1,18){
        FOR(i,1,n) p[i][lay]=p[p[i][lay-1]][lay-1];
        FOR(i,1,n) he[i][lay]=max(he[i][lay-1],he[p[i][lay-1]][lay-1]);
    }
    FOR(i,1,m) printf("%I64d\n",best+w[i]-query(v[i][0],v[i][1]));
}
int main(){
    prepare();
    solve();
}