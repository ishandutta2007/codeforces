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
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll g = 0;
    rep(i,n)g=gcd(g,a[i]);
    int ans = 0;
    for(ll i = 1 ; i<=1000000 ; ++i){
        if(i*i>g)break;
        if(i*i==g){
            ++ans;
            break;
        }
        if(g%i==0)ans+=2;
    }
    cout<<ans<<endl;
    return 0;
}