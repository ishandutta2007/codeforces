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
    ll n,m;
    cin>>n>>m;
    vector<ll> f(202020);
    f[0]=2, f[1]=2;
    rep(i,200000)f[i+2]=(f[i+1]+f[i])%mod;
    cout<<(f[n]+f[m]+mod-2)%mod<<endl;
    return 0;
}