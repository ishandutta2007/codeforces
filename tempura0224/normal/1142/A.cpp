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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll gcd(ll x,ll y){
    if(x<y)swap(x,y);
    return y?gcd(y,x%y) : x;
}

int main(){
    ll n,k;
    cin>>n>>k;
    int a,b;
    cin>>a>>b;
    ll ma=gcd(n*k,a+b);
    ll mi=ma;
    rep(i,1000000){ 
        ll ret=gcd(n*k,abs(a-b+k*i));
        ma=max(ma,ret);
        mi=min(mi,ret);
        ret=gcd(n*k,abs(a+b+k*i));
        ma=max(ma,ret);
        mi=min(mi,ret);
    }
    cout<<n*k/ma<<" "<<n*k/mi<<endl;
    return 0;
}