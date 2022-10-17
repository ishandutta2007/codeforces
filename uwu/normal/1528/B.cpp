#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=2e6+1;

ll pre[MAXN], dp[MAXN], add[MAXN];
vector<int> twos;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=2;i<=2*n;i+=2){
        for (int j=i+i;j<=2*n;j+=i){
            add[j]++;
        }
    }
    dp[0]=1, dp[1]=1;
    pre[0]=1, pre[1]=2;
    for (int i=2;i<=n;++i){
        dp[i]=pre[i-1]+add[i*2];
        pre[i]=pre[i-1]+dp[i];
        dp[i]%=mod;
        pre[i]%=mod;
    }
    cout << dp[n] << '\n';
}