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


int dp[120][120];
int main(){
    int n,r;
    cin>>n>>r;
    vector<pair<int,int>> posi, nega;
    rep(i,n){
        int x,y;
        cin>>x>>y;
        if(y>=0)posi.emplace_back(x,y);
        else nega.emplace_back(x,-y);
    }
    sort(posi.begin(),posi.end());
    int cnt = 0;
    for(auto p : posi){
        if(r>=p.first){
            ++cnt;
            r+=p.second;
        }
    }
    sort(nega.begin(),nega.end(),[](pair<int,int> i, pair<int,int> j){
        return i.first-i.second > j.first-j.second;
    });
    rep(i,n+1)rep(j,n+1){
        dp[i][j]=-inf;
    }
    dp[0][0]=r;
    int s = nega.size();
    rep(i,s){
        rep(j,s+1){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(dp[i][j]>=nega[i].first)dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]-nega[i].second);
        }
    }
    int ans = cnt;
    rep(i,s+1){
        if(dp[s][i]>=0)ans = max(ans,cnt+i);
    }
    cout<<ans<<endl;
    return 0;
}