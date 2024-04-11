#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+9;
const ll mod = 998244353;
int n,a[N];ll inv[N],dp[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    inv[0]=inv[1]=1;
    for(int i=2;i<=100;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    dp[1]=1;
    for(int i=1;i<=n;i++){
        dp[i+1]=(1ll+dp[i]*100ll%mod*inv[a[i]])%mod;
    }
    printf("%lld\n",dp[n+1]-1);
    return 0;
}
/*
dp[i+1]=1+dp[i]*100/pi
*/