#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int dp[MAXN], best[MAXN], n, ans=0x3f3f3f3f;
// best is answer, dp is ending with RL
string s;

void solve(){
    ms(dp,0x3f); ms(best,0x3f);
    dp[1]=0x3f3f3f3f; best[1]=0x3f3f3f3f;
    dp[0]=best[0]=0;
    for (int i=2;i<=n;++i){
        dp[i]=min({best[i-2]+(int)(s[i-2]!='R')+(int)(s[i-1]!='L')});
        best[i]=min({dp[i],dp[i-1],dp[i-2]+(int)(s[i-2]!='L')+(int)(s[i-1]!='R')+(i==2)*0x3f3f3f3f});
    }
    ans=min(ans,best[n]);
    //cout << s << " " << best[n] << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> s;
        ans=0x3f3f3f3f;
        solve();
        s+=s[0]; s=s.substr(1,n);
        solve();
        s+=s[0]; s=s.substr(1,n);
        solve();
        s+=s[0]; s=s.substr(1,n);
        solve();
        cout << ans << '\n';
    }
}