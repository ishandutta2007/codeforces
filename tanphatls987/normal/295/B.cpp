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

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e2+10;

int n,p[N],w[N][N],h[N];
ll ans[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n)
        FOR(j,1,n) scanf("%d",w[i]+j);
    FOR(i,1,n) scanf("%d",p+i);
}
void cal(int idx){
    int x=p[idx];
    w[x][n+1]=w[n+1][x]=inf;
    memset(h,0,sizeof(h));
    FOR(phase,idx+1,n){
        int sel=n+1;
        FOR(i,idx+1,n) if (!h[p[i]]&&w[x][p[i]]<w[x][sel]) sel=p[i];
        h[sel]=1;
//        printf("%d ",sel);
        FOR(i,idx+1,n) w[x][p[i]]=min(w[x][p[i]],w[x][sel]+w[sel][p[i]]);
    }
    memset(h,0,sizeof(h));
    FOR(phase,idx+1,n){
        int sel=n+1;
        FOR(i,idx+1,n) if (!h[p[i]]&&w[p[i]][x]<w[sel][x]) sel=p[i];
        h[sel]=1;
        FOR(i,idx+1,n) w[p[i]][x]=min(w[p[i]][x],w[p[i]][sel]+w[sel][x]);
    }
    FOR(i,idx,n)
        FOR(j,idx,n) w[p[i]][p[j]]=min(w[p[i]][p[j]],w[p[i]][x]+w[x][p[j]]);
}
void solve(){
    FORD(idx,n,1){
//        printf("%d\n",idx);
        cal(idx);
        FOR(t0,idx,n)
            FOR(t1,idx,n) ans[idx]+=w[p[t0]][p[t1]];
//        FOR(i,1,n)
//            FOR(j,1,n) cout<<w[i][j]<<" \n"[j==n];
    }
    FOR(i,1,n) printf("%I64d ",ans[i]);
}
int main(){
    prepare();
    solve();
}