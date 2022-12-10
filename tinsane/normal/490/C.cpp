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
const int MAXN = 1e6 + 10;

string s;
int a, b, st10[MAXN], pos(0), dp1[MAXN], dp2[MAXN];

void init()
{
    cin >> s >> a >> b;
    st10[0] = 1;
    for(int i(1); i < MAXN; ++i)
        st10[i] = (st10[i - 1] * 10) % b;
}

void solve()
{
    dp1[0] = 0;
    for(int i(1); i <= s.size(); ++i)
        dp1[i] = (dp1[i - 1] * 10 + s[i - 1] - '0') % a;
    dp2[s.size()] = 0;
    for(int i(s.size() - 1); i >= 0; --i)
        dp2[i] = (st10[s.size() - 1 - i] * (s[i] - '0') + dp2[i + 1]) % b;
    for(int i(1); i < s.size(); ++i)
    if(dp1[i] == 0 && dp2[i] == 0 && s[i] != '0')
    {
        pos = i;
        break;
    }
}

void output()
{
    if(pos)
    {
        cout << "YES\n";
        for(int i(0); i < pos; ++i)
            cout << s[i];
        cout << '\n';
        for(int i(pos); i < s.size(); ++i)
            cout << s[i];
    }
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}