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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-9;
const int MAXN = (1 << 20) + 30;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans(0);
    bool face[256];
    string mas[50];
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    for(int i(0); i < n - 1; ++i)
    for(int j(0); j < m - 1; ++j)
    {
        face['f'] = face['a'] = face['c'] = face['e'] = 0;
        face[mas[i][j]] = face[mas[i + 1][j]] = face[mas[i][j + 1]] = face[mas[i + 1][j + 1]] = 1;
        ans += (face['f'] && face['a'] && face['c'] && face['e']);
    }
    cout << ans;
    return 0;
}