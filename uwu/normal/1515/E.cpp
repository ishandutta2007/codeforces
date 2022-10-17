#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int inf=0x3f3f3f3f, MAXN=420;

ll mod;
ll dp[MAXN][MAXN], p2[MAXN], fact[MAXN], inv[MAXN];
ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod, e>>=1; 
    }
    return ret;
}
ll choose(int n, int k){ return fact[n]*inv[k]%mod*inv[n-k]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n >> mod;
    fact[0]=inv[0]=p2[0]=1;
    for (int i=1;i<=n;++i){
        p2[i]=p2[i-1]*2%mod;
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
    }
    dp[1][1]=1, dp[2][2]=2;
    for (int i=3;i<=n;++i){
        dp[i][i]=p2[i-1];
        for (int j=1;j<=i-2;++j){
            int k=i-j-1;
            for (int c=k;c<=n;++c){
                dp[i][c]=(dp[i][c]+dp[j][c-k]*p2[k-1]%mod*choose(c,k))%mod;
            }
        }
    }
    cout << accumulate(dp[n],dp[n]+1+n,0LL)%mod << '\n';
}