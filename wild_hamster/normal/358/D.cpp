#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll i,j,k,n,a[100500][3],dp[100500][2];
int main()
{
cin >> n;
for (j = 0; j < 3; j++)
    for (i = 0; i < n; i++)
        cin >> a[i][j];
dp[0][0] = a[0][0];
dp[0][1] = a[0][1];
for (i = 1; i <= n; i++)
    {
         dp[i][0]=max(dp[i-1][0]+a[i][1],dp[i-1][1]+a[i][0]);
         dp[i][1]=max(dp[i-1][0]+a[i][2],dp[i-1][1]+a[i][1]);
    }
cout << dp[n-1][0] << endl;
return 0;
}