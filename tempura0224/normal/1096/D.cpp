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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dp[101010][4];

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll a[n];
    rep(i,n)cin>>a[i];
    rep(i,n){
        rep(j,4)dp[i+1][j]=dp[i][j];
        if(s[i]=='h'){
            dp[i+1][0]+=a[i];
        }
        if(s[i]=='a'){
            dp[i+1][1]=min(dp[i+1][0],dp[i+1][1]+a[i]);
        }
        if(s[i]=='r'){
            dp[i+1][2]=min(dp[i+1][1],dp[i+1][2]+a[i]);
        }
        if(s[i]=='d'){
            dp[i+1][3]=min(dp[i+1][2],dp[i+1][3]+a[i]);
        }
    }
    cout<<dp[n][3]<<endl;
    return 0;
}