#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5050;

ll a[N],dp[N][2],pref[N];

int main(){
    int n,k,m;cin>>n>>k>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)pref[i]=pref[i-1]+a[i];
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j&1]=max(dp[i-1][j&1],dp[max(0,i-k)][(j-1)&1]+(pref[i]-pref[max(0,i-k)]));
        }
    }
    cout<<dp[n][m&1];
    return 0;
}