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
#include <unordered_set>
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e4 + 10;

struct rec
{
    int d, h;
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, ma(0), m;
    bool ok(1);
    rec mas[100000];
    cin >> m >> n;
    cin >> mas[0].d >> mas[0].h;
    ma = mas[0].h;
    for(int i(1); i < n; ++i)
        cin >> mas[i].d >> mas[i].h, ok &= (mas[i].d - mas[i - 1].d >= abs(mas[i].h - mas[i - 1].h)), 
        ma = max(ma, mas[i].h),
        ma = max(ma, max(mas[i].h, mas[i - 1].h) + (mas[i].d - mas[i - 1].d - abs(mas[i].h - mas[i - 1].h)) / 2);
    if(!ok)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    ma = max(ma, mas[0].h + mas[0].d - 1);
    ma = max(ma, mas[n - 1].h + m - mas[n - 1].d);
    cout << ma;
    return 0;
}