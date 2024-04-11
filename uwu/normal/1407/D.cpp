#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=3e5+1;

int arr[MAXN], dp[MAXN];
stack<int> s1,s2;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ms(dp,0x3f); dp[1]=0;
    for (int i=1;i<=n;++i) cin >> arr[i];
    s1.push(1), s2.push(1); int last=0;
    for (int i=2;i<=n;++i){
        while (!s1.empty()&&arr[i]>=arr[s1.top()]){
            dp[i]=min(dp[i],dp[s1.top()]+1);
            last=s1.top();
            s1.pop();
        }
        if (!s1.empty()&&arr[last]!=arr[i]) dp[i]=min(dp[i],dp[s1.top()]+1);
        s1.push(i);
        while (!s2.empty()&&arr[i]<=arr[s2.top()]){
            dp[i]=min(dp[i],dp[s2.top()]+1);
            last=s2.top();
            s2.pop();
        }
        if (!s2.empty()&&arr[last]!=arr[i]) dp[i]=min(dp[i],dp[s2.top()]+1);
        s2.push(i);
    }
    cout << dp[n] << '\n';
    
}