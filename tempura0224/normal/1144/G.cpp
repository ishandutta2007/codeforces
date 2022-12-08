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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int dp[202020][2];
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    dp[0][1]=-inf;
    dp[0][0]=inf;
    rep(i,n-1){
        dp[i+1][1]=inf;
        dp[i+1][0]=-inf;
        if(a[i+1]>a[i])dp[i+1][0]=dp[i][0];
        if(a[i+1]<a[i])dp[i+1][1]=dp[i][1];
        if(a[i+1]>dp[i][1])dp[i+1][0]=max(dp[i+1][0],a[i]);
        if(a[i+1]<dp[i][0])dp[i+1][1]=min(dp[i+1][1],a[i]);
    }
    if(dp[n-1][0]==-inf&&dp[n-1][1]==inf){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    vector<int> ans;
    int l=inf,d=-inf;
    for(int i=n-1;i>=0;--i){
        if(dp[i][0]==-inf){
            ans.push_back(1);
            d=a[i];
        }
        else if(dp[i][1]==inf){
            ans.push_back(0);
            l=a[i];
        }
        else if(a[i]>d){
            ans.push_back(1);
            d=a[i];
        }
        else if(a[i]<l){
            ans.push_back(0);
            l=a[i];
        }
        else assert(false);
    }
    reverse(ans.begin(),ans.end());
    for(auto e : ans)cout<<e<<" ";
    return 0;
}