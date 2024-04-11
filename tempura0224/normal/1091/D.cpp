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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

int main(){
    ll n;
    cin>>n;
    ll fact[n+1];
    fact[0]=1;
    rep(i,n)fact[i+1]=fact[i]*(i+1)%mod;
    ll ans=fact[n];
    ll res=1;
    rep(i,n){
        res=res*(n-i)%mod;
        ans+=(fact[n]-res+mod);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}