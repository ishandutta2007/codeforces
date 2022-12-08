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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<int> id;
    rep(i,n){
        if(a[i])id.push_back(i);
    }
    int cnt = id.size();
    vector<vector<vector<int>>> dp(81,vector<vector<int>>(81,vector<int>(3500,inf))),ndp(81,vector<vector<int>>(81,vector<int>(3500,inf))),upd(81,vector<vector<int>>(81,vector<int>(3500,inf)));
    dp[0][0][0]=0;
    rep(t,n){
        rep(i,min(t+1,cnt+1))rep(j,min(t+1, n-cnt+1))rep(k,(t+1)*t/2+1){
            if(dp[i][j][k]==inf)continue;
            if(j<n-cnt){
                ndp[i][j+1][k+j]=min(ndp[i][j+1][k+j],dp[i][j][k]);
            }
            if(i<cnt){
                ndp[i+1][0][k]=min(ndp[i+1][0][k],dp[i][j][k]+abs(t-id[i]));
            }
            dp[i][j][k]=inf;
        }
        dp.swap(ndp);
    }
    vector<int> ret(3500,inf);
    int res = (n-cnt) * (n-cnt-1) / 2;
    rep(j,81)rep(k,3500)ret[k]=min(dp[cnt][j][k],ret[k]);
    int sz = n*(n-1)/2 + 1;
    vector<int> ans(sz);
    rep(i,3500){
        if(ret[i]<sz)ans[ret[i]] = max(ans[ret[i]], res - i);
    }
    rep(i,sz - 1)ans[i+1]=max(ans[i],ans[i+1]);
    rep(i,sz)cout<<ans[i]<<" \n"[i+1==sz];
    return 0;
}