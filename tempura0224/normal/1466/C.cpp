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

int dp[101010][2][2];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        n+=2;
        rep(i,n+1)rep(j,2)rep(k,2)dp[i][j][k]=inf;
        s = "ZZ"+s;
        rep(j,2)rep(k,2)dp[2][j][k]=0;
        for(int i=2;i<n;i++){
            rep(k,2)dp[i+1][1][k]=min(dp[i][k][0],dp[i][k][1])+1;
            if(s[i]!=s[i-1]){
                dp[i+1][0][0]=dp[i][0][1];
                if(s[i]!=s[i-2])dp[i+1][0][0]=min(dp[i+1][0][0],dp[i][0][0]);
            }
            dp[i+1][0][1]=dp[i][1][1];
            if(s[i]!=s[i-2])dp[i+1][0][1]=min(dp[i+1][0][1],dp[i][1][0]);
        }
        int mi = inf;
        //for(int i=2;i<=n;i++){
        //    rep(j,2)rep(k,2)cout<<dp[i][j][k]<<" ";
        //    cout<<endl;
        //}
        rep(i,2)rep(j,2)mi = min(mi,dp[n][i][j]);
        cout<<mi<<endl;
    }
    return 0;
}