#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d2.inp","r",stdin)
#define OUTPUT freopen("d2.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e6+3;
const int N=1e6+10;

ll rev[N],fac[N],revfac[N];

ll C(int x,int y){
    return fac[x]*revfac[y]*revfac[x-y]%MOD;
}
void prepare(){
    fac[0]=1;
    REP(i,1,N) fac[i]=fac[i-1]*i%MOD;
    rev[1]=1;
    REP(i,2,N) rev[i]=MOD-(MOD/i)*rev[MOD%i]%MOD;
    revfac[0]=1;
    REP(i,1,N) revfac[i]=revfac[i-1]*rev[i]%MOD;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    int n,m;
    cin>>n>>m;
    ll ans=0;
    FOR(i,1,n) ans=(ans+C(i+m-1,m-1))%MOD;
    cout<<ans;
}