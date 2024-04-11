#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=2e5+1;

ll x[MAXN], y[MAXN];
ll dp[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int s; cin >> x[i] >> y[i] >> s;
        int j=upper_bound(x+1,x+1+i,y[i])-x;
        dp[i]=x[i]-y[i];
        dp[i]=(dp[i]+dp[i-1]-dp[j-1]+mod)%mod;
        ans[i]=(x[i]-x[i-1]+ans[i-1]+mod)%mod;
        if (s) ans[i]=(ans[i]+dp[i])%mod;
        dp[i]=(dp[i]+dp[i-1])%mod;
    }
    cout << (ans[n]+1)%mod << '\n';
}