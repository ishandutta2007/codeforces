#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e6+1;

ll dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    dp[1]=dp[2]=0; dp[3]=dp[4]=4; dp[5]=12;
    for (int i=6;i<MAXN;++i) dp[i]=(dp[i-2]*2+dp[i-1]+((i%3)?0:4))%mod;
    while (t--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}