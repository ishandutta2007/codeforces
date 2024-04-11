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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll dp[10105][105][2],i,j,n,k,d,m,rez;

int main()
{
    cin >> n >> k >> d;
    dp[0][0][0] = 1;
    for (m = 0; m < 101; m++)
    for (i = 0; i < 101; i++)
    {
        for (j = 1; j <= k; j++)
        {
            if (j >= d)
            {
                dp[i+j][m+1][1] += dp[i][m][0];
                dp[i+j][m+1][1] %= MOD;
            } else
            {
                dp[i+j][m+1][0] += dp[i][m][0];
                dp[i+j][m+1][0] %= MOD;
            }
            dp[i+j][m+1][1] += dp[i][m][1];
            dp[i+j][m+1][1] %= MOD;
        } 
    }
    for (i = 0; i <= 100; i++)
    {
        rez += dp[n][i][1];
        rez %= MOD;
    }
    cout << rez << endl;
    return 0;
}