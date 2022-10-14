#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000009
typedef int ll;
using namespace std;
ll k,oz,w,l,r,i,j,k1,k2,dr,n,m, t, qt, qh, md, dp[3][1005][1005], sum[3][1005][1005];
ll a[100500];
string s;
int main()
{
    cin >> n >> m >> k >> md;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        dp[0][a[i]][i]++;
    j = 0;
    for (i = 0; i <= k; i++)
        {
            sum[j%2][i][0] = dp[j%2][i][0];
            for (t = 1; t < n; t++)
            sum[j%2][i][t] = sum[j%2][i][t-1] + dp[j%2][i][t];
        }
    for (j = 1; j < m; j++)
    {
        for (i = 0; i <= k; i++)
            for (t = 0; t < n; t++)
            dp[j%2][i][t] = 0;
        for (i = 0; i <= k; i++)
            for (t = 0; t < n; t++)
            {
                dp[j%2][i+a[t]][t] += sum[(j-1)%2][i][t];
                dp[j%2][i+a[t]][t] %= md;
            //  cout << j << " " << i+a[t] << " " << dp[j][i+a[t]][t] << endl;
            }
            
        for (i = 0; i <= k; i++)
        {
            sum[j%2][i][0] = dp[j%2][i][0];
            for (t = 1; t < n; t++)
            sum[j%2][i][t] = (sum[j%2][i][t-1] + dp[j%2][i][t])%md;
        }
    }
    ll ans = 0;
    for (i = 0; i <= k; i++)
        for (t = 0; t < n; t++)
        ans = (ans+dp[(m-1)%2][i][t])%md;
    cout << ans << endl;
    return 0;
}