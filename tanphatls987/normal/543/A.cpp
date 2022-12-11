#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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

int n,m,b,mod,f[2][N][N]={0},h[N]={0},x,a[N];
int main(){
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    FOR(i,1,n) scanf("%d",a+i);
    f[0][0][0]=1;
    FOR(i,1,n){
        FOR(j,0,m)
            FOR(k,0,b) f[i%2][j][k]=f[(i-1)%2][j][k];
        FOR(j,1,m)
            FOR(k,a[i],b) f[i%2][j][k]=(f[i%2][j][k]+f[i%2][j-1][k-a[i]])%mod;
    }
    /*FOR(i,1,n){
        FOR(j,1,m)
            FOR(k,0,b) printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
    }*/
    int ans=0;
    FOR(i,0,b) ans=(ans+f[n%2][m][i])%mod;
    cout<<ans;
}