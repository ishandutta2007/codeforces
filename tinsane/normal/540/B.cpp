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
#include <unordered_map>
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
    ios_base::sync_with_stdio(0);
    int n, k, p, x, mas[1000], y, now(0), fp;
    cin >> n >> k >> p >> x >> y;
    for(int i(0); i < k; ++i)
        cin >> mas[i], now += mas[i];
    if(now + n - k > x)
    {
        cout << -1;
        return 0;
    }
    sort(mas, mas + k);
    for(fp = 0; fp < k; ++fp)
        if(mas[fp] >= y)
            break;
    if(fp == k)
    {
        if(k * 2 >= n + 1 || (n + 1) / 2 * y + now + (n - 1) / 2 - k > x)
        {
            cout << -1;
            return 0;
        }
        for(int i(0); i < (n + 1) / 2; ++i)
            cout << y << ' ';
        for(int i(k); i < (n - 1) / 2; ++i)
            cout << 1 << ' ';
        return 0;
    }
    ++fp;
    if(fp * 2 > n + 1)
    {
        cout << -1;
        return 0;
    }
    if(n - k <= (n + 1) / 2 - fp)
    {
        for(int i(k); i < n; ++i)
            cout << "1 ";
        return 0;
    }
    if(now + (n + 1) / 2 - fp + ((n - 1) / 2 - k + fp) * y > x)
    {
        cout << -1;
        return 0;
    }
    for(int i(fp); i < (n + 1) / 2; ++i)
        cout << "1 ";
    for(int i(k - fp); i < (n - 1) / 2; ++i)
        cout << y << ' ';
    return 0;
}