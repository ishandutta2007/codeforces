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
const int N=0;

ll sum,xors;
ll solve(){
    if (sum<xors) return 0;
    ll v=sum-xors;
    if (v&1) return 0;
    v>>=1;
    ll ans=1;
    FOR(i,0,50) if (v&(1LL<<i)){
        if (xors&(1LL<<i)) return 0;
    }else if (xors&(1LL<<i)) ans*=2;
    if (xors==sum) ans-=2;
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    cin>>sum>>xors;
    cout<<solve();
}