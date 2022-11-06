#include <cstdio>

long long a[60];

bool dp[51][51];
int n, k;

bool chk(long long min) {
    for(int i=0; i<=n; i++) for(int j=0; j<=k; j++) dp[i][j] = false;
    dp[0][0] = true;
    long long s = 0;
    for(int i=0; i<n; i++)for(int j=0; j<k; j++){
        if(!dp[i][j]) continue;
        s = 0;
        for(int u=i+1; u<=n; u++){
            s += a[u];
            if((s|min) == s) dp[u][j+1] = true;
        }
    }
    return dp[n][k];
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%lld", a+i);
    }
    long long ans = 0;
    for(int i=60; i>=0; i--){
        if(chk(ans | (1ll<<i))) ans |= (1ll<<i);
    }
    printf("%lld\n", ans);
    return 0;
}