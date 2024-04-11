#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, MAXN=1e5+1;
const ll inf=1e18+1;

ll dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    dp[0]=dp[1]=1;
    for (int i=2;i<MAXN;++i){
        dp[i]=dp[i-1]*2;
        dp[i]=min(dp[i],inf);
    }
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        if (k>dp[n]){
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans;
        int low=0;
        for (int i=n;i>=1;){
            int go=1;
            while (true){
                if (dp[i-go]>=k) break;
                k-=dp[i-go]; go++;
            }
            for (int i=low+go;i>low;--i) ans.push_back(i);
            i-=go; low=low+go;
        }
        for (int x:ans) cout << x << " ";
        cout << '\n';
    }
}