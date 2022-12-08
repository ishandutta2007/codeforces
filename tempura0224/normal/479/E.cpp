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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    --a;--b;
    vector<ll> dp(n+5);
    dp[a]=1;
    rep(i,k){
        vector<ll> ndp(n+5);
        rep(j,n){
            if(j<b){
                ndp[b]-=dp[j];
                ndp[max(0,2*j-b+1)]+=dp[j];
            }
            else if(j>b){
                ndp[b+1]+=dp[j];
                ndp[min(n,2*j-b)]-=dp[j];
            }
        }
        rep(j,n)ndp[j+1]+=ndp[j];
        rep(j,n)ndp[j]+=mod-dp[j];
        rep(j,n)ndp[j]%=mod;
        dp.swap(ndp);
    }
    ll ans=0;
    rep(i,n)ans+=dp[i];
    cout<<ans%mod<<endl;
    return 0;
}