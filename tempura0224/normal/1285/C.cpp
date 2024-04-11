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

ll gcd(ll x,ll y){
    return y?gcd(y,x%y):x;
}
int main(){
    ll n;
    cin>>n;
    ll ma = longinf;
    for(ll i = 1;i < 2000000;++i){
        if(n%i)continue;
        ll j = n/i;
        if(gcd(i,j)==1){
            if(max(i,j)<ma)ma=max(i,j);
        }
    }
    cout<<ma<<" "<<n/ma<<endl;
    return 0;
}