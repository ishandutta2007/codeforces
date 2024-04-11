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
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

#pragma comment(linker, "/STACK:1677721600")

const int MAXN = 1e6 + 10;
int pref[MAXN];
int n, m, nw, th, si;
long long ans(1);
bool can[MAXN];
string s;

void kmp()
{
    pref[0] = 0;
    int n = s.size();
    for(int i(1); i < n; ++i)
    {
        int j = pref[i - 1];
        for(; j > 0 && s[i] != s[j]; j = pref[j - 1]);
        if(s[i] == s[j]) ++j;
        pref[i] = j;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s;
    si = s.size();
    if(!m)
    {
        for(int i(0); i < n; ++i)
            ans *= 26,  ans%= MODUL;
        cout << ans;
        return 0;
    }
    cin >> nw;
    if(m == 1)
    {
        for(int i(0); i < n - si; ++i)
            ans *= 26,  ans%= MODUL;
        cout << ans;
        return 0;
    }
    for(int i(0); i < si; ++i)
        can[i] = 0;
    kmp();
    for(int i(pref[si - 1]); i > 0; i = pref[i - 1])
        can[si - i] = 1;
    n -= si;
    for(int i(1); i < m; ++i)
    {
        th = nw;
        cin >> nw;
        if(th + si > nw)
        {
            if(!can[nw - th])
            {
                cout << 0;
                return 0;
            }
            else
                n -= nw - th;
        }
        else
            n -= si;
    }
    for(int i(0); i < n; ++i)
        ans *= 26,  ans%= MODUL;
    cout << ans;
    return 0;
}