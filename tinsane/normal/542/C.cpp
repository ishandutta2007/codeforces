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
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e5 + 10;

long long gcd(long long a, long long b)
{
    return (a % b ? gcd(b, a % b) : b);
}

long long res(1), was[202], clen[202], cnum[202], now(0), ma[202], mac[202], res1;
int n, f[202];
bool fl1;

int dfs(int v, int len)
{
    if(clen[v] < 0)
    {
        was[v] = 0;
        clen[v] = len + clen[v];
        cnum[v] = now++;
        res *= (clen[v]) / gcd(res, clen[v]);
        mac[cnum[v]] = clen[v];
        return clen[v];
    }
    else if(clen[v] > 0)
        return -was[v];
    clen[v] = -len;
    int tmp = dfs(f[v], len + 1);
    cnum[v] = cnum[f[v]];
    clen[v] = clen[f[v]];
    if(tmp > 0)
    {
        was[v] = 0;
        return tmp - 1;
    }
    was[v] = -tmp + 1;
    ma[cnum[v]] = max(ma[cnum[v]], ((was[v] - 1) / clen[v] + 1));
    return tmp - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    ++n;
    ma[0] = 1;
    for(int i(1); i < n; ++i)
        cin >> f[i], was[i] = -1, clen[i] = 0, ma[i] = 1;
    for(int i(1); i < n; ++i)
    if(was[i] == -1)
        dfs(i, 1);
    res1 = res;
    for(int i(0); i < now; ++i)
    {
        ma[i] *= mac[i];
        if(res1 < ma[i])
            res1 = ((ma[i] - 1) / res + 1) * res;
    }
    cout << res1;
    return 0;
}


/*

50
2 3 1 5 6 7 8 9 10 11 4 4 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49


*/