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
const int MAXN = 1e5 + 10;

long long bpow(long long x, int p)
{
    return (p ? (p & 1) ? (bpow(x * x % MODUL, p / 2) * x) % MODUL : bpow(x * x % MODUL, p / 2) : 1);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int k;
    long long mas[1000], fact[2001], defact[2001], ans(1), sum(0);
    cin >> k;
    for(int i(0); i < k; ++i)
        cin >> mas[i], sum += mas[i];
    defact[0] = fact[0] = 1;
    for(int i(1); i < 2001; ++i)
        fact[i] = (i * fact[i - 1]) % MODUL, defact[i] = bpow(fact[i], MODUL - 2);
    ans = fact[sum - 1];
    sum = 0;
    for(int i(0); i < k; ++i)
        ans = (ans * defact[mas[i] - 1]) % MODUL;
    for(int i(0); i < k - 1; ++i)
        sum += mas[i], ans = (ans * bpow(sum, MODUL - 2)) % MODUL;
    cout << ans;
    return 0;
}