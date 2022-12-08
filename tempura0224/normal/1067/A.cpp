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

ll dp[101010][222][2];

int main(){
    int n;
    cin>>n;
    int a[n+1];
    rep(i,n)cin>>a[i];
    a[n]=0;
    rep(i,201)dp[0][i][0]=1;
    rep(i,n){
        if(a[i]>=0){
            dp[i+1][a[i]][0]=(dp[i][a[i]-1][0]+dp[i][a[i]-1][1])%mod;
            dp[i+1][a[i]][1]=(dp[i][a[i]][0]-dp[i][a[i]-1][0]+dp[i][200][1]-dp[i][a[i]-1][1]+2*mod)%mod;
        }
        else {
            rep(j,200){
                dp[i+1][j+1][0]=(dp[i][j][0]+dp[i][j][1])%mod;
                dp[i+1][j+1][1]=(dp[i][j+1][0]-dp[i][j][0]+dp[i][200][1]-dp[i][j][1]+2*mod)%mod;
            }
        }
        rep(j,200)(dp[i+1][j+1][0]+=dp[i+1][j][0])%=mod;
        rep(j,200)(dp[i+1][j+1][1]+=dp[i+1][j][1])%=mod;
    }
    cout<<dp[n][200][1]<<endl;
    return 0;
}