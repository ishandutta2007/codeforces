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

struct pa
{
    int a, b;
};

bool comp(pa f, pa s)
{
    return f.a < s.a;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, res(0);
    pa mas[MAXN];
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].a >> mas[i].b;
    sort(mas, mas + n, comp);
    int i(0);
    for(; i < n && mas[i].a < 0; ++i);
    int x = min(i, n - i) + 1;
    if(i == n - i)
    {
        for(int j(0); j < n; ++j)
            res += mas[j].b;
        cout << res;
        return 0;
    }
    if(i >= x)
    {
        for(int j(i); j < n; ++j)
            res += mas[j].b;
        for(int j(i - 1); x; --j, --x)
            res += mas[j].b;
        cout << res;
        return 0;
    }
    for(int j(0); j < i; ++j)
        res += mas[j].b;
    for(int j(i); x; ++j, --x)
        res += mas[j].b;
    cout << res;
    return 0;
}