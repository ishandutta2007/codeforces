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

string s, t, ans;
int n;

void init()
{
    cin >> s >> t;
}

void solve()
{
    ++s.back();
    for(int i(s.size() - 1); i > 0; --i)
    if(s[i] > 'z')
        s[i] = 'a', ++s[i - 1];
    if(s == t)
        ans = "No such string";
    else
        ans = s;
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