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
const int N=0;
const ll BASE[2][2]={{0,1},{1,1}};

ll mat[2][2]={0},tmp[2][2],cu[2][2],n,k;
int l,mod;
ll power(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
ll getfib(ll n){
    n--;
    mat[0][0]=mat[1][1]=1;
    FOR(i,0,1)
        FOR(j,0,1) cu[i][j]=BASE[i][j];
    while (n){
        if (n&1){
            FOR(i,0,1)
                FOR(j,0,1) tmp[i][j]=mat[i][j],mat[i][j]=0;
            FOR(i,0,1)
                FOR(j,0,1)
                    FOR(k,0,1) mat[i][j]=(mat[i][j]+tmp[i][k]*cu[k][j])%mod;
        }
        n>>=1;
        FOR(i,0,1)
            FOR(j,0,1) tmp[i][j]=cu[i][j],cu[i][j]=0;
        FOR(i,0,1)
            FOR(j,0,1)
                FOR(k,0,1) cu[i][j]=(cu[i][j]+tmp[i][k]*tmp[k][j])%mod;
//        FOR(i,0,1)
//            FOR(j,0,1) cout<<cu[i][j]<<" \n"[j==1];
    }
    return mat[1][1];
}
ll solve(){
    FOR(i,l,62) if (k&(1LL<<i)) return 0;
    ll v=getfib(n+2),ans=1,all=power(2,n);
    REP(i,0,l){
        if (k&(1LL<<i)) ans=ans*(all-v)%mod;
        else ans=ans*v%mod;
    }
    return (ans+mod)%mod;
}
int main(){
    cin>>n>>k>>l>>mod;
    cout<<solve();
}