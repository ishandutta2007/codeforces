#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=0;

ll n,m;
ll sum(ll L,ll R){
    ll len=(R-L+1);
    if (len&1) return (L+R)/2%MOD*(len%MOD)%MOD;
    return len/2%MOD*((L+R)%MOD)%MOD;
}
ll solve(){
    ll ans=0;
    if (m>n){
        ans=(m-n)%MOD*(n%MOD)%MOD;
        m=n;
    }
    int bar=int(sqrt(n));
    FOR(i,1,bar){
        if (i<=m) ans=(ans+n%i)%MOD;
        ll L=max(n/(i+1),1LL*bar)+1,R=min(n/i,m);
//        cout<<i<<" "<<L<<" "<<R<<'\n';
        if (L<=R){
            ll len=(R-L+1);
            ans=(ans+n%MOD*(len%MOD)-sum(L,R)*i%MOD+MOD)%MOD;
        }
    }
    return (ans+MOD)%MOD;
}
int main(){
    cin>>n>>m;
    cout<<solve();
}