#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};
int dp[200][4];
string s[2];
int rec(int n,int k){
    if(dp[n][k]!=-1)return dp[n][k];
    if(n==0)return 0;
    int ret=rec(n-1,0);
    int u=(k/2)|(s[0][n]=='X');
    int d=(k%2)|(s[1][n]=='X');
    if(u==0&&d==0){
        if(s[1][n-1]=='0')ret=max(ret,rec(n-1,1)+1);
        if(s[0][n-1]=='0')ret=max(ret,rec(n-1,2)+1);
    }
    if(u==0||d==0)if(s[0][n-1]=='0'&&s[1][n-1]=='0')ret=max(ret,rec(n-1,3)+1);
    return dp[n][k]=ret;
}
int main(){
    cin>>s[0]>>s[1];
    int n=s[0].size();
    rep(i,n)rep(j,4)dp[i][j]=-1;
    cout<<rec(n-1,0)<<endl;
    return 0;
}