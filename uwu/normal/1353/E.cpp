#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        char a;
        vector<int> arr(n+1);
        int dp[n+1]={0},cnt=0;
        for (int i=1;i<=n;++i){
            cin >> a;
            cnt+=a-'0';
            arr[i]=a-'0';
        }
        int ans=cnt;
        for (int i=1;i<=n;++i){
            dp[i]=cnt-(arr[i]*2-1);
            if (i>k){
                dp[i]=min(dp[i],dp[i-k]-(arr[i]*2-1));
            }
            ans=min(ans,dp[i]);
        }
        cout << ans << '\n';
    }
}