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


int dp[111][111][2];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    rep(i,n+1)rep(j,n+1)rep(k,2)dp[i][j][k]=inf;
    dp[0][0][0]=0,dp[0][0][1]=0;
    rep(i,n)rep(j,i+1){
        int k=i-j;
        if(a[i]==0){
            dp[k+1][j][0]=min(dp[k+1][j][0],dp[k][j][0]);
            dp[k+1][j][0]=min(dp[k+1][j][0],dp[k][j][1]+1);
            dp[k][j+1][1]=min(dp[k][j+1][1],dp[k][j][0]+1);
            dp[k][j+1][1]=min(dp[k][j+1][1],dp[k][j][1]);
        }
        else if(a[i]%2){
            dp[k][j+1][1]=min(dp[k][j+1][1],dp[k][j][0]+1);
            dp[k][j+1][1]=min(dp[k][j+1][1],dp[k][j][1]);
        }
        else {
            dp[k+1][j][0]=min(dp[k+1][j][0],dp[k][j][0]);
            dp[k+1][j][0]=min(dp[k+1][j][0],dp[k][j][1]+1);
        }
    }
    cout<<min(dp[n/2][(n+1)/2][1],dp[n/2][(n+1)/2][0])<<endl;

    return 0;
}