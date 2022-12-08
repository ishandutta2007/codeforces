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

int dp[300][300][300];

int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> a(3);
    rep(i,300)rep(j,300)rep(k,300)dp[i][j][k]=inf;
    vector<vector<int>> nxt(26,vector<int>(n+1,inf));
    rep(i,n){
        rep(j,26)nxt[j][n-i-1]=nxt[j][n-i];
        nxt[s[n-i-1]-'a'][n-i-1]=n-i-1;
    }
    dp[0][0][0]=0;
    vector<string> y(3);
    while(q--){
        char c;
        cin>>c;
        if(c=='+'){
            int x;
            char t;
            scanf("%d %c",&x,&t);
            a[x-1]++;
            y[x-1]+=t;
            if(x==1){
                REP(i,a[0],a[0]+1)REP(j,0,a[1]+1)REP(k,0,a[2]+1){
                    dp[i][j][k]=inf;
                    if(i>0&&dp[i-1][j][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[0][i-1]-'a'][dp[i-1][j][k]]+1);
                    if(j>0&&dp[i][j-1][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[1][j-1]-'a'][dp[i][j-1][k]]+1);
                    if(k>0&&dp[i][j][k-1]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[2][k-1]-'a'][dp[i][j][k-1]]+1);
                }
            }
            else if(x==2){
                REP(i,0,a[0]+1)REP(j,a[1],a[1]+1)REP(k,0,a[2]+1){
                    dp[i][j][k]=inf;
                    if(i>0&&dp[i-1][j][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[0][i-1]-'a'][dp[i-1][j][k]]+1);
                    if(j>0&&dp[i][j-1][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[1][j-1]-'a'][dp[i][j-1][k]]+1);
                    if(k>0&&dp[i][j][k-1]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[2][k-1]-'a'][dp[i][j][k-1]]+1);
                }
            }
            else {
                REP(i,0,a[0]+1)REP(j,0,a[1]+1)REP(k,a[2],a[2]+1){
                    dp[i][j][k]=inf;
                    if(i>0&&dp[i-1][j][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[0][i-1]-'a'][dp[i-1][j][k]]+1);
                    if(j>0&&dp[i][j-1][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[1][j-1]-'a'][dp[i][j-1][k]]+1);
                    if(k>0&&dp[i][j][k-1]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[y[2][k-1]-'a'][dp[i][j][k-1]]+1);
                }
            }
        }
        else {
            int x;
            scanf("%d",&x);
            --x;
            y[x].pop_back();
            --a[x];
        }
        if(dp[a[0]][a[1]][a[2]]!=inf)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}