#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int INF = (int)1e9;
const int N = (int)1e6 + 100;

int dp[N][2];

int main()
{

    string str;
    cin >> str;
    int n = (int)str.length();   

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = dp[i][1] = INF;

    dp[1][0] = 1;
    dp[1][1] = 2;
    for (int i = 1; i < n; i++)
    {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + (str[i] == '1' ? 1 : 0));
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2 + (str[i] == '1' ? 1 : 0));
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (str[i] == '0' ? 1 : 0));
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (str[i] == '1' ? 1 : 0));         
    }

    cout << min(dp[n][0], dp[n][1]);

    return 0;
}