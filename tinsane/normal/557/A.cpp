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
const int MAXN = 2e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, a1, a2, a3, b1, b2, b3, f, s, t;
    cin >> n;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    f = min(b1, n - a2 - a3);
    cout << f << ' ';
    n -= f;
    s = min(b2, n - a3);
    cout << s << ' ' << n - s;
    return 0;
}