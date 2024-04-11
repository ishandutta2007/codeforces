#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2005, mod = 1e9+7;
int dp[MN][MN], n, m, i, j, t, r, ans;
string s;

int main(){
    cin >> n >> m >> s;
    for(char c : s){
        if(c=='(') t++;
        else if(t) t--;
        else r++;
    }
    dp[0][0]=1;
    for(i=1;i<=n-m;i++){
        for(j=0;j<=i;j++){
            if(j){
                dp[i][j]+=dp[i-1][j-1];
                if(dp[i][j]>=mod) dp[i][j]-=mod;
            }
            dp[i][j]+=dp[i-1][j+1];
            if(dp[i][j]>=mod) dp[i][j]-=mod;
        }
    }
    for(i=0;i<=n-m;i++){
        for(j=0;j+max(r,t)<=n-m;j++)
            ans = (ans+1LL*dp[i][r+j]*dp[n-m-i][t+j])%mod;
    }
    printf("%d\n",ans);
    return 0;
}