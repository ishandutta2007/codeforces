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
    int n, k, go(0), ti(0), m, mas[MAXN];
    bool f;
    cin >> n >> k;
    for(int i(0); i < k; ++i)
    {
        f = 0;
        cin >> m;
        for(int j(0); j < m; ++j)
            cin >> mas[j];
        if(mas[0] != 1)
            ti += m - 1;
        else
        {
            for(int j(1); j < m && mas[j] - mas[j - 1] == 1; ++j, ++go);
            ti += m - go - 1;
        }
    }
    cout << ti + n - go - 1;
    return 0;
}