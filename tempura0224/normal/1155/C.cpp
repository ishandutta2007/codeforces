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
    if(x<y)swap(x,y);
    return y?gcd(y,x%y) : x;
}

int main(){
    int n,m;
    cin>>n>>m;
    ll ans=0;
    ll a0=0;
    rep(i,n){
        ll x;
        cin>>x;
        if(i==0)a0=x;
        x-=a0;
        ans=gcd(ans,x);
    }
    rep(i,m){
        ll y;
        cin>>y;
        if(ans%y==0){
            cout<<"YES"<<endl;
            cout<<a0<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}