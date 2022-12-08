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
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d[80][80];

int dp[80][11];
int main(){
    int n, k;
    cin>>n>>k;
    rep(i,n)rep(j,n)cin>>d[i][j];
    vector<int> col(n);
    rep(i,n/2)col[i]=1;
    int ans = inf;
    rep(_,10000){
        shuffle(col.begin(), col.end(), rng);
        rep(i,n)rep(j,k+1)dp[i][j]=inf;
        dp[0][0]=0;
        rep(j,k){
            rep(i,n){
                rep(t,n){
                    if(col[t]!=col[i])dp[t][j+1]=min(dp[t][j+1],dp[i][j]+d[i][t]);
                }
            }
        }
        ans =min(ans,dp[0][k]);
    }
    cout<<ans<<endl;
    return 0;
}