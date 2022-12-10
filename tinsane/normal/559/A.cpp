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
    double a, b, c, mas[6], s(0);
    long long res(0);
    for(int i(0); i < 6; ++i)
        cin >> mas[i];
    a = sqrt(mas[0] * mas[0] + mas[1] * mas[1] + mas[0] * mas[1]);
    b = sqrt(mas[2] * mas[2] + mas[3] * mas[3] + mas[2] * mas[3]);
    c = sqrt(mas[4] * mas[4] + mas[5] * mas[5] + mas[4] * mas[5]);
    res = mas[0] * mas[1] + mas[2] * mas[3] + mas[4] * mas[5];
    s = sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));
    res += s / sqrt(3.0) + 1e-7;
    cout << res;
    return 0;
}