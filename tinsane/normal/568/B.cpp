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
const double eps = 1e-7;
const int MAXN = 4e3 + 10;

long long bp(long long x, long long p)
{
    return (p ? ((p & 1) ? (bp(x * x % MODUL, p / 2) * x % MODUL) : (bp(x * x % MODUL, p / 2))) : 1);
}
int n;
long long fact[MAXN], defact[MAXN], ans(1), ndp[MAXN];

long long cnk(int n, int k)
{
    return fact[n] * defact[k] % MODUL * defact[n - k] % MODUL;
}


void init()
{
    cin >> n;
    fact[0] = 1;
    defact[0] = 1;
    for(long long i(1); i < MAXN; ++i)
        fact[i] = (fact[i - 1] * i) % MODUL, 
        defact[i] = bp(fact[i], MODUL - 2);
    ndp[0] = ndp[1] = 1;
    for(int i(2); i < MAXN; ++i)
    {
        ndp[i] = 0;
        for(int j(0); j < i; ++j)
            ndp[i] = (ndp[i] + cnk(i - 1, j) * ndp[i - j - 1]) % MODUL;
    }
}

void solve()
{
    for(int i(1); i < n; ++i)
        ans = (ans + cnk(n, i) * ndp[i]) % MODUL;
}

void output()
{
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}