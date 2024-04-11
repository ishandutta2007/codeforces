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
const int MAXN = 1e3 + 10;

string s;
int n;

void init()
{
    cin >> s;
    n = s.size();
}

void solve()
{
    for(int i(0); i < n; ++i)
    if((s[i] - '0') % 2 == 0 && s[i] < s[n - 1])
    {
        swap(s[i], s[n - 1]);
        cout << s;
        return;
    }
    for(int i(n - 1); i >= 0; --i)
    if((s[i] - '0') % 2 == 0)
    {
        swap(s[i], s[n - 1]);
        cout << s;
        return;
    }
    cout << -1;
}

void output()
{
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}