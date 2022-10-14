#include <iostream>
using namespace std;
typedef long long ll;
ll i,n,j,k,a[105],b[105];
ll dp[105][25000];
int main()
{
cin >> n >> k;
for (i = 0; i < n; i++)
cin >> a[i];
for (i = 0; i < n; i++)
{
cin >> b[i];
b[i] = b[i]*k - a[i];
}
for (i = 0; i <= n; i++)
for (j = 0; j < 24000; j++)
dp[i][j] = -(ll)1e+9;
dp[0][12000] = 0;
for (i = 1; i <= n; i++)
{
for (j = 2000; j < 22000; j++)
{
dp[i][j] = max(dp[i][j], dp[i-1][j]);
dp[i][j] = max(dp[i][j], dp[i-1][j - b[i-1]] + a[i-1]);
}
}
if (dp[n][12000])
cout << dp[n][12000] << endl;
else
cout << -1 << endl;
return 0;
}