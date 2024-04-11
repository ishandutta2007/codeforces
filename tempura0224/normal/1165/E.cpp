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
const ll mod=998244353 ;

int main(){
    ll n;
    cin>>n;
    ll a[n],b[n];
    rep(i,n){
        cin>>a[i];
        a[i]=a[i]*(i+1)*(n-i);
    }
    rep(i,n)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    ll ans=0;
    rep(i,n){
        a[i]%=mod;
        ans+=a[i]*b[i]%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}