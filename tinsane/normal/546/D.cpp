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
#include <algorithm>
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e6 + 10;

unsigned int dp[MAXN];
vector<int> pr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i(2); i < MAXN; ++i)
        dp[i] = 0;
    for(int i(2); i < MAXN; ++i)
    {
        if(dp[i] == 0)
        {
            dp[i] = i;
            pr.push_back(i);
        }
        for(int j(0); j < pr.size() && pr[j] <= dp[i] && i * pr[j] < MAXN; ++j)
            dp[i * pr[j]] = pr[j];
    }
    dp[1] = 0;
    for(int i(2); i < MAXN; ++i)
        dp[i] = dp[i / dp[i]] + 1;
    for(int i(2); i < MAXN; ++i)
        dp[i] += dp[i - 1];
    int t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << dp[a] - dp[b] << '\n';
    }
    return 0;
}