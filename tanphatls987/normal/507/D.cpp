#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e3+10;

int n,m,mod,p10[2][N],f[N][110][10]={0},g[N][110][10]={0};
int solve(){
    ll ans=0;
    p10[0][0]=p10[1][0]=1;
    FOR(i,1,n) {
        p10[0][i]=(1LL*p10[0][i-1]*10)%m;
        p10[1][i]=(1LL*p10[1][i-1]*10)%mod;
    }
    FOR(i,0,9) f[1][i%m][i]++;
    REP(k,1,n){
        //FOR(i,0,9)
            //REP(j,0,m) printf("%d %d %d %d %d\n",k,i,j,f[k][j][i],g[k][j][i]);
        FOR(i,0,9) {
            ans=(ans+(1LL*(f[k][0][i]-g[k][0][i]-(i==0)+mod)*p10[1][n-k-1])%mod*9)%mod;
            g[k][0][i]=f[k][0][i]-(i==0);
        }
        REP(i,0,m)
            FOR(j,0,9)
                FOR(j1,0,9) {
                    f[k+1][(i+p10[0][k]*j)%m][j]=(f[k+1][(i+p10[0][k]*j)%m][j]+f[k][i][j1])%mod;
                    g[k+1][(i+p10[0][k]*j)%m][j]=(g[k+1][(i+p10[0][k]*j)%m][j]+g[k][i][j1])%mod;
                }
    }
    FOR(i,1,9) ans=(ans+f[n][0][i]-g[n][0][i]+mod)%mod;
    return ans;
}
int main(){
    cin>>n>>m>>mod;
    cout<<solve();
}