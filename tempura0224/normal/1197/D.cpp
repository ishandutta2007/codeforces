#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(ll)(m) ; i < (ll) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n+1];
    a[0]=0;
    rep(i,n)cin>>a[i+1];
    ll ans =0 ;
    vector<ll> res(m,longinf);
    ll sum = 0;
    rep(i,n+1){
        sum+=a[i];
        rep(j,m){
            ll ret = sum - (i/m)*k;
            if(j<(i%m))ret -= k;
            ans=max(ans,ret-res[j]);
        }
        res[i%m]=min(res[i%m],sum-(i/m)*k);
    }
    cout<<ans<<endl;
    return 0;
}