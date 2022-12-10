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
const double eps = 1e-9;
const int MAXN = 2e3 + 10;

int n, ln[MAXN], rn[MAXN], x[MAXN], h, lnd[MAXN], rnd[MAXN];
double p, prob[MAXN][MAXN][2][2], dp[MAXN][MAXN][2][2], res, np, ndp;

void init()
{
    cin >> n >> h >> p;
    for(int i(0); i < n; ++i)
        cin >> x[i];
    x[n] = -3e8 - 10;
    x[n + 1] = 3e8 + 10;
    n += 2;
    sort(x, x + n);
    ln[0] = 0;
    lnd[0] = h;
    for(int i(1); i < n; ++i)
    if(x[i] - x[i - 1] < h)
        ln[i] = ln[i - 1], lnd[i] = lnd[i - 1] + x[i] - x[i - 1];
    else
        ln[i] = i, lnd[i] = h;
    rn[n - 1] = n - 1;
    rnd[n - 1] = h;
    for(int i(n - 2); i >= 0; --i)
    if(x[i + 1] - x[i] < h)
        rn[i] = rn[i + 1], rnd[i] = rnd[i + 1] + x[i + 1] - x[i];
    else
        rn[i] = i, rnd[i] = h;
    prob[1][n - 2][0][0] = 1;
}

void solve()
{
    for(int len = n - 3; len >= 0; --len)
    for(int i(1); i < n - len - 1; ++i)
    for(int a(0); a < 2; ++a)
    for(int b(0); b < 2; ++b)
    if(prob[i][i + len][a][b] > 0)
    {
        dp[i][i + len][a][b] /= prob[i][i + len][a][b];
        ndp = dp[i][i + len][a][b];

        np = prob[i][i + len][a][b] * p / 2;
        
        prob[i + 1][i + len][0][b] += np;
        dp[i + 1][i + len][0][b] += np * (ndp + (a == 0 ? 
            min(h, x[i] - x[i - 1]) : 
            min(h, x[i] - x[i - 1] - h)));

        int nr = max(i, ln[i + len]) - 1;
        prob[i][nr][a][0] += np;
        if(ln[i + len] <= i - 1)
            dp[i][nr][a][0] += np * (ndp + lnd[i + len] - lnd[i - 1]);
        else if(ln[i + len] == i)
            dp[i][nr][a][0] += np * (ndp + lnd[i + len] - (a == 1 ? max(0, 2 * h - (x[i] - x[i - 1])) : 0));
        else
            dp[i][nr][a][0] += np * (ndp + lnd[i + len]);

        np = prob[i][i + len][a][b] * (1 - p) / 2;
        prob[i][i + len - 1][a][1] += np;
        dp[i][i + len - 1][a][1] += np * (ndp + (b == 0 ? 
            min(h, x[i + len + 1] - x[i + len] - h) : 
            min(h, x[i + len + 1] - x[i + len])));

        int nl = min(i + len, rn[i]) + 1;
        prob[nl][i + len][1][b] += np;
        if(rn[i] >= i + len + 1)
            dp[nl][i + len][1][b] += np * (ndp + rnd[i] - rnd[i + len + 1]);
        else if(rn[i] == i + len)
            dp[nl][i + len][1][b] += np * (ndp + rnd[i] - (b == 0 ? max(0, 2 * h - (x[i + len + 1] - x[i + len])) : 0));
        else
            dp[nl][i + len][1][b] += np * (ndp + rnd[i]);
    }
}

void output()
{
    for(int i(1); i < n; ++i)
    for(int a(0); a < 2; ++a)
    for(int b(0); b < 2; ++b)
        res += dp[i][i - 1][a][b];
    cout << setprecision(9) << fixed << res;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
 }