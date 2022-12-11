#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("tmp.inp","r",stdin)
#define OUTPUT freopen("tmp.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+10;

int g[N][N],f[N][N],a[2],n,m,c[N][N];
priority_queue <iii> q;
void prepare(){
    REP(i,0,N){
        c[i][0]=1;
        FOR(j,1,i) c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
}
bool optimize(int xa,int ya,int xb,int yb,ll v){
    bool ok=(g[xa][ya]+1<g[xb][yb]);
    if (ok) f[xb][yb]=0;
    if (g[xa][ya]+1<=g[xb][yb]) f[xb][yb]=(f[xb][yb]+v)%MOD;
    if (ok){
        g[xb][yb]=g[xa][ya]+1;
        q.push(iii(-g[xb][yb],ii(xb,yb)));
    }
    return g[xa][ya]+1<=g[xb][yb];
}
bool minimize(int &x,int y){
    if (x>y) x=y;else return 0;
    return 1;
}
void solve(){
    FOR(i,0,a[0])
        FOR(j,0,a[1]) g[i][j]=inf;
    g[a[0]][a[1]]=0;
    f[a[0]][a[1]]=1;
    q.push(iii(0,ii(a[0],a[1])));
    while (!q.empty()){
        int i=q.top().Y.X,j=q.top().Y.Y,cw=-q.top().X;
        q.pop();
        if (cw>g[i][j]) continue;
//        printf("%d %d %d %d\n",i,j,g[i][j],f[i][j]);
        FOR(i1,0,i)
            FOR(j1,(i1==0)?1:0,j){
                if (i1+2*j1>m) break;
                if (i1==i&&j1==j){
                    optimize(i,j,0,0,f[i][j]);
                    continue;
                }
                ll com=1LL*f[i][j]*c[i][i1]%MOD*c[j][j1]%MOD;
                FOR(i2,0,a[0]-i+i1)
                    FOR(j2,(i2==0)?1:0,a[1]-j+j1){
                        if (i2+2*j2>m) break;
                        if (!optimize(i,j,i-i1+i2,j-j1+j2,com*c[a[0]-i+i1][i2]%MOD*c[a[1]-j+j1][j2])) break;
                    }
            }
    }
    if (g[0][0]==inf) cout<<"-1\n0";
    else cout<<g[0][0]*2-1<<'\n'<<f[0][0];
}
int main(){
    prepare();
    cin>>n>>m;
    m/=50;
    int x;
    FOR(i,1,n) cin>>x,a[x/50-1]++;
    solve();
}