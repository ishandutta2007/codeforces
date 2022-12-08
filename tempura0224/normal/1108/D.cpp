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


int dp[202020][3];
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    rep(i,n){
        dp[i+1][0]=min(dp[i][1],dp[i][2]);
        dp[i+1][1]=min(dp[i][0],dp[i][2]);
        dp[i+1][2]=min(dp[i][1],dp[i][0]);
        if(s[i]!='R')++dp[i+1][0];
        if(s[i]!='G')++dp[i+1][1];
        if(s[i]!='B')++dp[i+1][2];
    }
    string ans="";
    int idx=0;
    rep(i,3)if(dp[n][i]<dp[n][idx])idx=i;
    cout<<dp[n][idx]<<endl;
    string RGB="RGB";
    ans+=RGB[idx];
    rep(i,n-1){
        int idx1=(idx+1)%3,idx2=(idx+2)%3;
        if(dp[n-i-1][idx1]<dp[n-i-1][idx2]){
            idx=idx1;
            ans+=RGB[idx];
        }
        else {
            idx=idx2;
            ans+=RGB[idx];
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}