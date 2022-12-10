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
const int MAXN = 5e4 + 10;

string s, t;
int cnt[256], a(0), b(0);

void init()
{
    for(int i(0); i < 256; ++i)
        cnt[i] = 0;
    cin >> s >> t;
    for(int i(0); i < t.size(); ++i)
        ++cnt[t[i]];
}

void solve()
{
    for(int i(0); i < s.size(); ++i)
    if(cnt[s[i]])
        --cnt[s[i]], s[i] = 0, ++a;
    for(int i(0); i < s.size(); ++i)
    if(s[i])
    if(s[i] <= 'Z')
    {
        if(cnt[s[i] + 'a' - 'A'])
            --cnt[s[i] + 'a' - 'A'], ++b;
    }
    else if(cnt[s[i] + 'A' - 'a'])
        --cnt[s[i] + 'A' - 'a'], ++b;
}

void output()
{
    cout << a << ' ' << b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}