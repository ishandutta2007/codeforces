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


int ns[55][26], nt[55][26];
int dp[1010][55][55];

int main(){
    string c;cin>>c;
    string s,t;cin>>s>>t;
    int n=c.size();
    int a=s.size(), b=t.size();
    rep(i,a+1){
        rep(j,26){
            string u = s.substr(0,i) + char('a'+j);
            rep(k,i+2){
                if(s.substr(0,k)==u.substr(i+1-k))ns[i][j]=k;
            }
        }
    }
    rep(i,b+1){
        rep(j,26){
            string u = t.substr(0,i) + char('a'+j);
            rep(k,i+2){
                if(t.substr(0,k)==u.substr(i+1-k))nt[i][j]=k;
            }
        }
    }
    rep(i,n+1)rep(j,a+1)rep(k,b+1)dp[i][j][k]=-inf;
    dp[0][0][0]=0;
    rep(i,n)rep(j,a+1)rep(k,b+1){
        if(dp[i][j][k]==-inf)continue;
        if(c[i]=='*'){
            rep(l,26){
                int nj=ns[j][l], nk=nt[k][l];
                int ret = dp[i][j][k];
                if(nj==a)++ret;
                if(nk==b)--ret;
                dp[i+1][nj][nk]=max(dp[i+1][nj][nk],ret);
            }
        }
        else {
            int l = c[i]-'a';
            int nj=ns[j][l], nk=nt[k][l];
            int ret = dp[i][j][k];
            if(nj==a)++ret;
            if(nk==b)--ret;
            dp[i+1][nj][nk]=max(dp[i+1][nj][nk],ret);
        }
    }
    int ans = -inf;
    rep(i,a+1)rep(j,b+1)ans = max(dp[n][i][j],ans);
    cout<<ans<<endl;
    return 0;
}