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
const int MAXN = 3e3 + 10;

int m, s, ts;
stack<char> ans;

void init()
{
    cin >> m >> s;
}

void solve()
{
}

void output()
{
    if(m == 1 && s == 0)
    {
        cout << "0 0";
        return;
    }
    if(!s || m * 9 < s)
    {
        cout << "-1 -1";
        return;
    }
    if(s <= m * 9 - 8)
    {
        cout << '1';
        ts = s - 1;
        for(int i(1); i < m; ++i)
        if(!ts)
            ans.push('0');
        else if(ts >= 9)
            ans.push('9'), ts -= 9;
        else
            ans.push((char) ts + '0'), ts = 0;
        for(; ans.size(); cout << ans.top(), ans.pop());
    }
    else
    {
        cout << s - (m - 1) * 9;
        for(int i(1); i < m; ++i)
            cout << '9';
    }
    cout << ' ';
    for(int i(0); i < m; ++i)
    if(!s)
        cout << '0';
    else if(s >= 9)
        cout << '9', s -= 9;
    else
        cout << (char) (s + '0'), s = 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}