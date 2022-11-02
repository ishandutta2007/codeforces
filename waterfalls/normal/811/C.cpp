#include <bits/stdc++.h>
using namespace std;

int n;
int a[5013];
bool ok[5013][5013];
int cost[5013][5013];
int dp[5013];

int low[5013], high[5013];
bool has[5013];


int main() {
scanf("%d",&n);
for (int i=0;i<5013;i++) low[i] = n+1;
for (int i=1;i<=n;i++) {
scanf("%d",&a[i]);
low[a[i]] = min(low[a[i]],i);
high[a[i]] = max(high[a[i]],i);
}
for (int i=1;i<=n;i++) {
memset(has,0,sizeof has);
int need = i;
bool isbad = false;
for (int j=i;j<=n;j++) {
cost[i][j] = cost[i][j-1];
if (!has[a[j]]) cost[i][j] ^= a[j];
has[a[j]] = 1;
need = max(need, high[a[j]]);
if (low[a[j]]<i) isbad = true;
if (!isbad && j>=need) ok[i][j] = 1;
}
}

for (int i=0;i<n;i++) {
dp[i+1] = max(dp[i+1], dp[i]);
for (int j=i+1;j<=n;j++) if (ok[i+1][j]) {
dp[j] = max(dp[j], dp[i]+cost[i+1][j]);
}
}
printf("%d\n",dp[n]);

return 0;
}