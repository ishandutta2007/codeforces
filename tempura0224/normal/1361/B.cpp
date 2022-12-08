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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

ll powmod(ll n,ll k){
    ll ret=1;
    bool upd1=false, upd2=false;
    while(k){
        if(k&1){
            ret=ret*n;
            if(ret>2e6||upd2)upd1=true;
            ret%=mod;
        }
        n=n*n;
        if(n>2e6)upd2=true;
        n%=mod;
        k>>=1;
    }
    if(upd1)return ret+mod;
    else return ret;
}


void solve(){
    int n;ll p;
    cin>>n>>p;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll diff=0;
    int c=a[0];
    bool upd=false;
    rep(i,n){
        diff=diff*powmod(p,c-a[i]);
        if(diff>2e6){
            upd=true;
            diff%=mod;
        }
        if(upd||diff>0){
            diff+=mod-1;
            diff%=mod;
        }
        else {
            diff+=1;
        }
        c=a[i];
    }
    diff=diff*powmod(p,c)%mod;
    cout<<diff<<'\n';
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    rep(i,t)solve();
    return 0;
}