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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<ll> a(n+1), b(n+1), c(n);
    rep(i,n){
        cin>>a[i+1];
        b[i]=a[i+1];
        c[i]=a[i+1];
        rep(j,k)c[i]*=x;
    }
    rep(i,n){
        a[i+1]|=a[i];
        b[n-i-1]|=b[n-i];
    }
    ll ans=0;
    rep(i,n)ans=max(ans,(a[i]|c[i]|b[i+1]));
    cout<<ans<<endl;
    return 0;
}