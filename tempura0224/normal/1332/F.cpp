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
constexpr ll mod=998244353 ;
vector<int> v[303030];
ll dp[303030][3];

void dfs(int x,int p){
        dp[x][0]=1;dp[x][1]=1;
    for(auto to:v[x]){
        if(to==p)continue;
        dfs(to,x);
        ll nd0=0, nd1=0, nd2=0;
        nd0 += dp[x][0]*(2*dp[to][0]+dp[to][1]+2*dp[to][2])%mod;
        nd1 += dp[x][1]*(dp[to][0]+dp[to][2])%mod;
        nd2 += dp[x][1]*dp[to][0]%mod;
        nd2 += dp[x][2]*(2*dp[to][0]+dp[to][2])%mod;
        dp[x][0]=nd0%mod;
        dp[x][1]=nd1%mod;
        dp[x][2]=nd2%mod;
    }
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][2]+mod-1)%mod<<endl;
    return 0;
}