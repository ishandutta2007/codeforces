#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const ll inf=1e18;
int n;
ll a[2][N],dp[2][N];
int main(){
    int n;
    scanf("%i",&n);
    for(int i=0;i<2;i++)for(int j=0;j<n;j++)scanf("%lld",&a[i][j]);
    ll pref[2]={0,0};
    for(int j=0;j<n;j++){
        for(int i=0;i<2;i++){
            dp[i][j]=max(dp[i][j],pref[1-i]+a[i][j]);
        }
        for(int i=0;i<2;i++){
            pref[i]=max(pref[i],dp[i][j]);
        }
    }
    printf("%lld",max(dp[0][n-1],dp[1][n-1]));
    return 0;
}