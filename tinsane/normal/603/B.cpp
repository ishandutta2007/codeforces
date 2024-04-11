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
const int MAXN = 1e5 + 10;

inline int mul(int a, int b, int mod)
{
    return ((ll) a * b) % mod;
}

inline int sum(int a, int b, int mod)
{
    return ((ll)a + b) % mod;
}

int p, k, ans = 1;

void init()
{
    cin >> p >> k;
}

void solve()
{
    if (k == 0)
    {
        for(int i(1); i < p; ++i)
            ans = mul(ans, p, MODUL);
        return;
    }
    if (k == 1)
    {
        for(int i(0); i < p; ++i)
            ans = mul(ans, p, MODUL);
        return;
    }
    int per = 1, t = k;
    for(; t != 1; ++per, t = mul(t, k, p));
    int st = (p - 1) / per;
    for(int i(0); i < st; ++i)
        ans = mul(ans, p, MODUL);
}

void output()
{
    cout << ans;
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