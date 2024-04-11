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
const int MAXN = 1e5 + 10;

int n, x;
vector<int> mas[4];

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> x, mas[x].push_back(i + 1);
}

void solve()
{
}

void output()
{
    x = min(mas[1].size(), min(mas[2].size(), mas[3].size()));
    cout << x << '\n';
    for(int i(0); i < x; ++i)
        cout << mas[1][i] << ' ' << mas[2][i] << ' ' << mas[3][i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}