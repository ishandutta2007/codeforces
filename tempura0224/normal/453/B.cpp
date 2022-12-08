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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


const int p[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int dp[111][1<<16];
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    int mask[54]={};
    rep(i,54){
        rep(j,16)if(i%p[j]==0)mask[i]|=(1<<j);
    }
    rep(i,111)rep(j,1<<16)dp[i][j]=inf;
    dp[0][0]=0;
    rep(i,n){
        rep(j,1<<16){
            rep(k,54)if((mask[k]&j)==0)dp[i+1][mask[k]|j]=min(dp[i+1][mask[k]|j],dp[i][j]+abs(k-a[i]));
        }
    }
    int mi=inf,ret=-1;
    rep(i,1<<16){
        if(dp[n][i]<mi)mi=dp[n][i],ret=i;
    }
    vector<int> ans;
    rep(i,n){
        rep(j,54){
            if((mask[j]|ret)!=ret)continue;
            if(dp[n-i-1][ret^mask[j]]+abs(a[n-i-1]-j)==dp[n-i][ret]){
                ans.push_back(j);
                ret^=mask[j];
                break;
            }
        }
    }
    rep(i,n){
        cout<<ans[n-i-1]<<" ";
    }
    return 0;
}