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


vector<ll> dp[1<<14][14];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s[n];
    rep(i,n)cin>>s[i];
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n)a[i][j]=s[i][j]=='1';
    int m = 1<<n;
    rep(i,n){
        dp[1<<i][i].push_back(1);
    }
    rep(i,m){
        int sz = __builtin_popcount(i);
        rep(j,n){
            if(((1<<j)&i)==0)continue;
            rep(k,n){
                if(((1<<k)&i)!=0)continue;
                int nxt = i+(1<<k);
                if(dp[nxt][k].size()==0){
                    dp[nxt][k].resize(1<<sz);
                }
                rep(l,dp[i][j].size()){
                    dp[nxt][k][l+(1<<(sz-1))*a[j][k]]+=dp[i][j][l];
                }
            }
        }
    }
    rep(i,m/2){
        ll ans = 0;
        rep(j,n)ans += dp[m-1][j][i];
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}