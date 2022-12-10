#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <list>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:167772160")

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    vector<int> dev[2001];
    long long dp[2001][2001];           // dp[n][k]
    cin >> n >> k;

    for(int i(1); i < 2001; ++i)
    for(int j(1); j <= i; ++j)
    if(i % j == 0)
        dev[i].push_back(j);
    
    for(int i(0); i < 2001; ++i)
        dp[i][0] = dp[0][i] = 0;
    for(int i(1); i < 2001; ++i)
        dp[i][1] = i;
    for(int i(2); i < 2001; ++i)
        dp[1][i] = 1;

    for(int i(2); i < 2001; ++i)
    for(int j(2); j < 2001; ++j)
    {
        dp[i][j] = dp[i - 1][j];
        for(int i1(0); i1 < dev[i].size(); ++i1)
            dp[i][j] += dp[dev[i][i1]][j - 1] - dp[dev[i][i1] - 1][j - 1];
        dp[i][j] %= MODUL;
        dp[i][j] += MODUL;
        dp[i][j] %= MODUL;
    }
    cout << dp[n][k];
    return 0;
}