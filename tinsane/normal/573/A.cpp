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

int gcd(int a, int b)
{
    return (a % b ? gcd(b, a % b) : b);
}

int n, mas[MAXN], g(0);
bool f(1);

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i], g = gcd(g, mas[i]);
}

void solve()
{
    for(int i(0); i < n; ++i)
    {
        mas[i] /= g;
        for(; mas[i] % 2 == 0; mas[i] /= 2);
        for(; mas[i] % 3 == 0; mas[i] /= 3);
        f &= mas[i] == 1;
    }
}

void output()
{
    if(f)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}