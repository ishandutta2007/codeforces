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
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n+1);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    a.resize(k+1);
    vector<int> t(n+1,0);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        t[x]=max(y,t[x]);
    }
    rep(i,k)a[i+1]+=a[i];
    vector<ll> dp(k+1,longinf);
    dp[0]=0;
    rep(i,k){
        REP(j,1,i+2){
            dp[i+1]=min(dp[i+1],dp[i+1-j]+a[i+1]-a[i+1-(j-t[j])]);
        }
    }
    cout<<dp[k]<<endl;
    return 0;
}