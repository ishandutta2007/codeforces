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


ll dp[202020][10];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    dp[0][0]=0;
    rep(i,9)dp[0][i+1]=-longinf;
    rep(i,n){
        int k;
        cin>>k;
        vector<ll> v1(3,-longinf),v2(1,-longinf),v3(1,-longinf);
        rep(j,k){
            int c,d;
            cin>>c>>d;
            if(c==1)v1.push_back(d);
            if(c==2)v2.push_back(d);
            if(c==3)v3.push_back(d);
        }
        sort(v1.rbegin(),v1.rend());
        sort(v2.rbegin(),v2.rend());
        sort(v3.rbegin(),v3.rend());
        rep(j,10){
            dp[i+1][j]=dp[i][j];
        }
        rep(j,10){
            dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],dp[i][j]+(j==9?2:1)*max({v3[0],v2[0],v1[0]}));
        }
        rep(j,10){
            dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],dp[i][j]+v1[0]+v1[1]+(j>=8?v1[0]:0));
            dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],dp[i][j]+v1[0]+v2[0]+(j>=8?max(v1[0],v2[0]):0));
        }
        rep(j,10){
            dp[i+1][(j+3)%10]=max(dp[i+1][(j+3)%10],dp[i][j]+v1[0]+v1[1]+v1[2]+(j>=7?v1[0]:0));
        }
    }
    ll ans = 0;
    rep(i,10)ans = max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}