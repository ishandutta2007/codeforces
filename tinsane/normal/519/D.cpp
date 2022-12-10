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
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

long long dp[MAXN], cost[26], res(0);
int n, cou(0);
map<long long, int> cnt;
string s;

void init()
{
    for(int i(0); i < 26; ++i)
        cin >> cost[i];
    cin >> s;
    n = s.size();
    dp[0] = 0;
    for(int i(0); i < n; ++i)
        dp[i + 1] = dp[i] + cost[s[i] - 'a'];
}

void solve()
{
    for(int c(0); c < 26; ++c)
    {
        cnt.clear();
        for(int i(0); i < n; ++i)
        if(s[i] == 'a' + c)
        {
            res += cnt[dp[i]];
            ++cnt[dp[i + 1]];
        }
    }
}

void output()
{
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}