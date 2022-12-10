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
const int MAXN = 1e3 + 10;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, fn(1), to;
    cin >> k;
    if(!(k & 1))
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if(k == 1)
    {
        cout << "2 1\n1 2";
        return 0;
    }
    cout << (k + 2) * 2 << ' ' << (k + 2) * k << '\n';
    cout << "2 3" << '\n';
    for(int i(4); i <= k + 2; ++i)
        cout << "1 " << i << '\n' << "2 " << i << '\n' << "3 " << i << '\n';
    for(int i(4); i < k + 3; ++i)
    {
        for(int j(i + 2); j < k + 3; ++j)
            cout << i << ' ' << j << '\n';
        ++i;
        for(int j(i + 1); j < k + 3; ++j)
            cout << i << ' ' << j << '\n';
    }

    cout << k + 3 << " 1\n";
    cout << k + 4 << ' ' << k + 5 << '\n';

    for(int i(k + 6); i <= 2 * k + 4; ++i)
        cout << k + 3 << ' ' << i << '\n' << k + 4 << ' ' << i << '\n' << k + 5 << ' ' << i << '\n';
    for(int i(k + 6); i < 2 * k + 5; ++i)
    {
        for(int j(i + 2); j < 2 * k + 5; ++j)
            cout << i << ' ' << j << '\n';
        ++i;
        for(int j(i + 1); j < 2 * k + 5; ++j)
            cout << i << ' ' << j << '\n';
    }
    return 0;
}