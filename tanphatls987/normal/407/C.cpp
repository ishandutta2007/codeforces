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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+120,M=101;

int f[M+1][N]={0},n,m,x,y,k,a[N];
ll fac[N],rev[N],refac[N];
ll C(int x,int y){
    if (y>x) return 0;
    return fac[x]*refac[y]%MOD*refac[x-y]%MOD;
}
void prepare(){
    fac[0]=1;
    REP(i,1,N) fac[i]=fac[i-1]*i%MOD;
    rev[1]=1;
    REP(i,2,N) rev[i]=MOD-rev[MOD%i]*(MOD/i)%MOD;
    refac[0]=1;
    REP(i,1,N) refac[i]=refac[i-1]*rev[i]%MOD;
}
void addsingle(int x,int y,int v){
//    printf("%d %d %d\n",x,y,v);
    f[x][y]=(f[x][y]+v)%MOD;
    f[x][y+1]=(f[x][y+1]+MOD-v)%MOD;
}
int main(){
//    INPUT;
    prepare();
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    while (m--){
        scanf("%d%d%d",&x,&y,&k);
        FOR(i,0,min(y-x,k)) {
            addsingle(M-i,x,C(k,i));
            addsingle(M-i,y+1-i,MOD-C(k+y-x-i,k-i));
        }
    }

    FOR(j,1,M)
        FOR(i,1,n) f[j][i]=(f[j][i]+f[j][i-1])%MOD;
//    FOR(j,M-2,M){
//        FOR(i,1,n) printf("%d ",f[j][i]);ENDL;
//    }
    FOR(i,1,M)
        FOR(j,1,n) f[i][j]=(f[i][j]+(f[i][j-1]+f[i-1][j-1])%MOD)%MOD;
//    FOR(j,M-2,M){
//        FOR(i,1,n) printf("%d ",f[j][i]);ENDL;
//    }
    FOR(i,1,n) printf("%d ",(a[i]+f[M][i])%MOD);
}