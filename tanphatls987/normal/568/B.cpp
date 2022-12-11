#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=4e3+10;

int g[N][N],c[N][N],n,f[N];
void prepare(){
    c[0][0]=1;
    FOR(i,1,n){
        c[i][0]=1;
        FOR(j,1,i) c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
}
int solve(){
    g[0][0]=f[0]=1;
    FOR(i,1,n)
        FOR(j,1,i) {
            g[i][j]=(g[i-1][j-1]+1LL*g[i-1][j]*j)%MOD;
            f[i]=(f[i]+g[i][j])%MOD;
        }
//    FOR(i,1,n) cout<<g[i]<<" \n"[i==n];
    int ans=0;
    FOR(i,1,n) ans=(ans+1LL*f[n-i]*c[n][i])%MOD;
    return ans;
}
int main(){
    cin>>n;
    prepare();
    cout<<solve();
}