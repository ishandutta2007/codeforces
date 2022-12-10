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
typedef long long ll;

//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

int n, ans(0);
string s;

void init()
{
    cin >> n >> s;
}

void solve()
{
    int cma = 1, tmp = 1, c = 1, cnt = 1;
    for(int i(1); i < n; ++i)
    {
        if (s[i] == s[i - 1])
            ++c;
        else
        {
            ++tmp;
            if (c > cma)
                cma = c, cnt = 1;
            else if(c == cma)
                ++cnt;
            c = 1;
        }
    }
    if (c > cma)
        cma = c, cnt = 1;
    else if(c == cma)
        ++cnt;
    if (cma > 2 || (cma == 2 && cnt > 1))
        ans = tmp + 2;
    else if(cma == 2)
        ans = tmp + 1;
    else
        ans = tmp;
}

void output()
{
    cout << ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
 }