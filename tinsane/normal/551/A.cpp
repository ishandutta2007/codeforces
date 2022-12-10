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
const int MAXN = 1e6 + 10;

struct pp
{
    int x, num;
};

bool comp(pp f, pp s)
{
    return f.x > s.x;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, res[3000], place(1), np(2);
    pp mas[3000];
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].x, mas[i].num = i;
    sort(mas, mas + n, comp);
    res[mas[0].num] = place;
    for(int i(1); i < n; ++i, ++np)
        if(mas[i].x == mas[i - 1].x)
            res[mas[i].num] = place;
        else
            place = res[mas[i].num] = np;
    for(int i(0); i < n; ++i)
        cout << res[i] << ' ';
    return 0;
}