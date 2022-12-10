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

//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;

long long bpow(long long x, long long p)
{
    if(p == 0)
        return 1;
    if(p % 2 == 1)
        return bpow(x * x % MODUL, p / 2) * x % MODUL;
    else
        return bpow(x * x % MODUL, p / 2);
}

long long n, l, k, tn, cnt[MAXN], ans(0), ft, sum;
long long mas[MAXN], past[MAXN], ind[MAXN];

void init()
{
    cin >> n >> l >> k;
    for(int i(0); i < n; ++i)
        cin >> mas[i], cnt[i] = 1;
    tn = l % n;
    ft = l / n;
    for(int i(0); i < tn; ++i)
        past[i] = mas[i];

    sort(mas, mas + n);
    sort(past, past + tn);

    for(int i(0), j(0); i < n && j < tn; ++i)
        for(; j < tn && mas[i] == past[j]; ++j)
            ind[j] = i;
}

void solve()
{
    for(int i1(1); i1 <= k; ++i1)
    {
        for(int i(0); i < tn; ++i)
            ans = (ans + cnt[ind[i]]) % MODUL;

        if(i1 > ft)
            break;

        sum = 0;
        for(int i(0); i < n;)
        {
            sum += cnt[i];
            int j(i + 1);
            for(; j < n && mas[j] == mas[i]; ++j)
                sum += cnt[j];
            sum %= MODUL;
            for(; i < j; ++i)
                cnt[i] = sum;
        }

        ans = (ans + (ft - i1 + 1) % MODUL * cnt[n - 1]) % MODUL;
    }
}

void output()
{
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
}