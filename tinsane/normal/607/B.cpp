#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <unordered_map>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

#define mk make_pair

typedef pair<int, int> pii;
typedef long long ll;

//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;

const int N = 5e2 + 10;
int n, mas[N], dp[N][N];

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
}

void solve()
{
    for(int i(0); i < n; ++i)
        dp[i][i] = dp[i + 1][i] = 1;
    for(int l(1); l < n; ++l)
    for(int i(0); i + l < n; ++i)
    {
        dp[i][i + l] = MAXINT;
        for(int k(i); k < i + l; ++k)
            dp[i][i + l] = min(dp[i][i + l], dp[i][k] + dp[k + 1][i + l]);
        if (mas[i] == mas[i + l])
            dp[i][i + l] = min(dp[i][i + l], dp[i + 1][i + l - 1]);
    }
}

void output()
{
    cout << dp[0][n - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
 }