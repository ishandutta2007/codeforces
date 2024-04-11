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
int kmp[200001], n;
long long dp[200001], var[200001], /*doo[1000000], */cs[200001];
string s, t;
/*
long long dget(int beg, int end, int now, int L, int R)
{
    if(L == beg && R == end)
        return doo[now];
    if(L > R)
        return 0;
    return (dget(beg, (beg + end) >> 1, now << 1, L, MIN(R, (beg + end) >> 1)) 
        + dget(((beg + end) >> 1) + 1, end, (now << 1) + 1, MAX(L, ((beg + end) >> 1) + 1), R)) % MODUL;
}

void dins(int beg, int end, int now, int val, long long vat)
{
    if(beg == end)
    {
        doo[now] = vat;
        return;
    }
    if(val > (beg + end) >> 1)
        dins(((beg + end) >> 1) + 1, end, (now << 1) + 1, val, vat);
    else
        dins(beg, ((beg + end) >> 1), (now << 1) + 1, val, vat);
    doo[now] = (doo[now << 1] + doo[(now << 1) + 1]) % MODUL;
}*/

void pref()
{
    kmp[0] = 0;
    for(int i(1); i < n; ++i)
    {
        int j = kmp[i - 1];
        for(; j > 0 && s[i] != s[j]; j = kmp[j - 1]);
        if(s[i] == s[j])
            ++j;
        kmp[i] = j;
    }
}

int main()
{
    cin >> t >> s;
    int m(s.size()), last(-1);
    s += '#';
    s += t;
    n = s.size();
    pref();
    //dins(0, n - 1, 1, m, 0);
    var[m] = 0;
    dp[m] = 0;
    cs[m] = 0;
    for(int i(m + 1); i < n; ++i)
    {
        if(kmp[i] == m)
            if(last == -1)
            {
                last = i + 1;
                var[i] = dp[i] = i - m * 2 + 1;
                //dins(0, n - 1, 1, i, dp[i]);
                cs[i] = (cs[i - 1] + dp[i]) % MODUL;
            }
            else
            {
                dp[i] = dp[i - 1];
                var[i] = var[i - 1] + 1 + i - last;
                /*for(int j(last - m); j <= i - m; ++j)
                {
                    var[i] += dp[j];
                    var[i] %= MODUL;
                }*/
                var[i] += (cs[i - m] + MODUL - cs[last - m - 1]) % MODUL;
                var[i] %= MODUL;
                /*var[i] += dget(0, n - 1, 1, last - m, i - m);
                var[i] %= MODUL;*/
                dp[i] += var[i];
                dp[i] %= MODUL;
                last = i + 1;
                //dins(0, n - 1, 1, i, dp[i]);
                cs[i] = (cs[i - 1] + dp[i]) % MODUL;
            }
        else
        {
            dp[i] = (dp[i - 1] + var[i - 1]) % MODUL;
            var[i] = var[i - 1];
            //dins(0, n - 1, 1, i, dp[i]);
            cs[i] = (cs[i - 1] + dp[i]) % MODUL;
        }
    }
    cout << dp[n - 1];
    return 0;
}