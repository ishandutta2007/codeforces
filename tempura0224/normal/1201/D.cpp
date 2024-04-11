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

int main(){
    int h,w,n,q;
    cin>>h>>w>>n>>q;
    vector<int> v[h];
    rep(i,n){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
    }
    rep(i,h)sort(v[i].begin(),v[i].end());
    vector<ll> ok;
    ok.push_back(-longinf);
    ok.push_back(longinf);
    rep(i,q){
        int x;
        cin>>x;
        --x;
        ok.push_back(x);
    }
    sort(ok.begin(),ok.end());
    ll pl = 0, pr = 0;
    ll dp[2][202020];
    rep(i,2)rep(j,202020)dp[i][j]=longinf;
    dp[0][1]=dp[1][1]=0;
    if(v[0].size()){
        pl=v[0][0];
        pr=v[0].back();
        dp[0][1]=2*pr-pl;
        dp[1][1]=pr;
    }
    int maxh = 1;
    REP(i,1,h){
        if(v[i].empty()){
            dp[0][i+1]=dp[0][i]+1;
            dp[1][i+1]=dp[1][i]+1;
            continue;
        }
        int nl = v[i][0], nr = v[i].back();
        auto itr = lower_bound(ok.begin(),ok.end(),pl);
        dp[0][i+1]=min(dp[0][i+1],dp[0][i]+abs(*itr-pl)+abs(nr-*itr)+abs(nr-nl)+1);
        dp[1][i+1]=min(dp[1][i+1],dp[0][i]+abs(*itr-pl)+abs(nl-*itr)+abs(nr-nl)+1);
        --itr;
        dp[0][i+1]=min(dp[0][i+1],dp[0][i]+abs(*itr-pl)+abs(nr-*itr)+abs(nr-nl)+1);
        dp[1][i+1]=min(dp[1][i+1],dp[0][i]+abs(*itr-pl)+abs(nl-*itr)+abs(nr-nl)+1);

        itr = lower_bound(ok.begin(),ok.end(),pr);
        dp[0][i+1]=min(dp[0][i+1],dp[1][i]+abs(*itr-pr)+abs(nr-*itr)+abs(nr-nl)+1);
        dp[1][i+1]=min(dp[1][i+1],dp[1][i]+abs(*itr-pr)+abs(nl-*itr)+abs(nr-nl)+1);
        --itr;
        dp[0][i+1]=min(dp[0][i+1],dp[1][i]+abs(*itr-pr)+abs(nr-*itr)+abs(nr-nl)+1);
        dp[1][i+1]=min(dp[1][i+1],dp[1][i]+abs(*itr-pr)+abs(nl-*itr)+abs(nr-nl)+1);
        pl = nl;
        pr = nr;
        maxh = max(i+1,maxh);
    }
    cout<<min(dp[0][maxh],dp[1][maxh])<<endl;
    return 0;
}