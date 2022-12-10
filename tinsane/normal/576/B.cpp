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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

int n, p[MAXN];
bool used[MAXN];

void init()
{
    cin >> n;
    for(int i(1); i <= n; ++i)
        cin >> p[i];
}

void solve()
{
    for(int i(1); i <= n; ++i)
    if(p[i] == i)
    {
        cout << "YES\n";
        for(int j(1); j <= n; ++j)
        if(j != i)
            cout << i << ' ' << j << '\n';
        return;
    }
    for(int t(1); t <= n; ++t)
    if(p[p[t]] == t)
    {
        for(int j(1); j <= n; ++j)
            used[j] = 0;
        used[t] = used[p[t]] = 1;
        for(int i(1); i <= n; ++i)
        if(!used[i])
        {
            int cnt = 0;
            for(int j(i); !used[j]; j = p[j], ++cnt)
                used[j] = 1;
            if(cnt & 1)
            {
                cout << "NO";
                return;
            }
        }
        cout << "YES\n";
        cout << t << ' ' << p[t] << '\n';
        used[t] = used[p[t]] = 0;
        for(int i(1); i <= n; ++i)
        if(used[i])
        {
            bool cnt = 0;
            for(int j(i); used[j]; used[j] = 0, j = p[j], cnt = !cnt)
            if(cnt)
                cout << t << ' ' << j << '\n';
            else
                cout << p[t] << ' ' << j << '\n';
        }
        return;
    }
    cout << "NO";
}

void output()
{
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}