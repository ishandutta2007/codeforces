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

vector<int> v[252525];
vector<pair<int,int>>dp[252525];

pair<int,int> dfs(int x,int p){
    dp[x].push_back({0,x});
    for(auto to:v[x]){
        if(to==p)continue;
        auto q = dfs(to,x);
        q.first++;
        dp[x].push_back(q);
    }
    sort(dp[x].begin(),dp[x].end());
    return dp[x].back();
}

void rdfs(int x,int p){
    int m = dp[x].size();
    sort(dp[x].begin(),dp[x].end());
    for(auto to:v[x]){
        if(to==p)continue;
        auto q = dp[x][m-1];
        if(q.second == dp[to].back().second){
            if(m>=2)q = dp[x][m-2];
            else q = {-1,-1};
        }
        q.first++;
        dp[to].push_back(q);
        rdfs(to,x);
    }
}

int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    rdfs(1,0);
    int ans = 0, idx = -1;
    rep(i,n+1)reverse(dp[i].begin(),dp[i].end());
    rep(i,n+1){
        if(dp[i].size()>=3){
            int ret= 0 ;
            rep(j,3)ret += dp[i][j].first;
            if(ret>ans){
                ans = ret;
                idx = i;
            }
        }
    }
    cout<<ans<<endl;
    rep(j,3)cout<<dp[idx][j].second<<" ";
    cout<<endl;
    return 0;
}