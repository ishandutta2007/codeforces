#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5050;
int a[N];
ll dp[2][N];
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    vector<int> xs;
    for(int i=1;i<=n;i++)xs.push_back(a[i]);
    sort(xs.begin(),xs.end());
    for(int i=0;i<n;i++)dp[1][i]=abs(a[1]-xs[i]);
    for(int i=2;i<=n;i++){
        ll mn=1e18;
        for(int j=0;j<n;j++){
            mn=min(mn,dp[1-(i%2)][j]);
            dp[i%2][j]=mn+abs(xs[j]-a[i]);
        }
    }
    ll ans=1e18;
    for(int i=0;i<n;i++)ans=min(ans,dp[n%2][i]);
    printf("%lld",ans);
    return 0;
}