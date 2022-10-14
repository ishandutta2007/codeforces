#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

string s;
int n,i;
int dp[2000000][2];

int main()
{
      cin >> s;
    n = s.size();
    dp[0][1] = 1000000000;
    for (i=1;i<=n;i++)
    {   
        if (s[i-1] == '0')
        {                   
         dp[i][0] = min(dp[i-1][1]+1, dp[i-1][0]);
         dp[i][1] = dp[i-1][1]+1;
        } else
        {
         dp[i][0] = min(dp[i-1][1] + 1, dp[i-1][0] + 1);
         dp[i][1] = min(dp[i-1][1], dp[i-1][0]+1);
        }
    }
    cout << min(dp[n][0], dp[n][1]+1) << endl;
    return 0;
}