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
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, ans(1), ta;
    bool inv[100];
    string mas[100];
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    for(int t(0); t < n; ++t)
    {
        for(int i(0); i < n; ++i)
            inv[i] = '1' - mas[t][i];
        ta = 0;
        for(int i(0); i < n; ++i)
        {
            bool f(1);
            for(int j(0); j < n; ++j)
                f &= (mas[i][j] + inv[j] == '1');
            ta += f;
        }
        ans = max(ans, ta);
    }
    cout << ans;
    return 0;
}