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
const int MAXN = 5e5 + 10;
int n;

void init()
{
    cin >> n;
}

void solve()
{
}

void output()
{
    if(n == 1)
        cout << "1\n1";
    else if(n == 2)
        cout << "1\n1";
    else if(n == 3)
        cout << "2\n1 3";
    else if(n == 4)
        cout << "4\n3 1 4 2";
    else
    {
        cout << n << '\n';
        for(int i(1); i <= n; ++++i)
            cout << i << ' ';
        for(int i(2); i <= n; ++++i)
            cout << i << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}