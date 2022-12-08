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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int q;cin>>q;
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        ll dp[2];
        dp[0]=0;
        dp[1]=-longinf;
        rep(i,n){
            ll n0 = max(dp[1]-a[i],dp[0]);
            ll n1 = max(dp[0]+a[i],dp[1]);
            dp[0]=n0;dp[1]=n1;
        }
        cout<<max(dp[0],dp[1])<<endl;
    }
    return 0;
}