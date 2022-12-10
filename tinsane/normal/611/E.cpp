#define _CRT_SECURE_NO_WARNINGS
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
#include <bitset>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef unsigned int uint;

#ifdef MEM_EXT
const int MMEM = 6e7;
int cmem = 0;
char mem[MMEM];
void * operator new (size_t n)
{
    return (void*)(mem + ((cmem += n) - n));
}
void operator delete (void*) {}
#endif

const double PI = 3.1415926535897932384626433;
const int P = 1e9 + 7;
const int INF = 1e9 + 2;
const ll LINF = 2e18 + 2;
const double eps = 1e-9;

const int N = 2e5 + 10;
int n, a, b, c, ans, tans, tans1;
deque<int> mas;
int lb, ub;

void init()
{
    cin >> n >> a >> b >> c;
    mas.resize(n);
    for (int i(0); i < n; ++i)
        cin >> mas[i];
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
}

bool cmpb(int f, int s)
{
    if (f <= b && s <= b) 
        return f > s;
    else 
        return f < s;
}

bool cmpc(int f, int s)
{
    if (f <= c && s <= c)
        return f > s;
    else
        return f < s;
}

void clr()
{
    for (int i(n - 1); i >= 0; --i)
        if (mas[i] > b + c)
            mas.pop_back(), ++ans;
    n = mas.size();
    lb = upper_bound(mas.begin(), mas.end(), a + c) - mas.begin();
    ub = 0;
    for (; ub < n && mas[ub] <= a; ++ub);
    ans += n - lb;
    for (; mas.size() > lb; mas.pop_back());
    for (int i(0); i < min(ub, n - lb); ++i)
        mas.pop_front();
    n = mas.size();

    ub = 0;
    for (; ub < n && mas[ub] <= b; ++ub);
    lb = upper_bound(mas.begin(), mas.end(), max(c, a + b)) - mas.begin();
    sort(mas.begin(), mas.end(), cmpb);
    ans += n - lb;
    for (; mas.size() > lb; mas.pop_back());
    for (int i(0); i < min(ub, n - lb); ++i)
        mas.pop_front();
    n = mas.size();
}
int end(int x, int y, int z)
{
    int k = min(x, min(y, z)), tans = k;
    x -= k;
    y -= k;
    z -= k;
    if (z == 0)
        tans += (x + y + 1) / 2;
    else if (y == 0)
    {
        k = min(x, (z + 1) / 2);
        tans += k;
        x -= k;
        z -= min(z, 2 * k);
        if (x != 0)
            tans += (x + 1) / 2;
        else
            tans += (z + 2) / 3;
    }
    else
    {
        k = min(z, y / 2);
        tans += k;
        z -= k;
        y -= k * 2;
        if (z == 0)
            tans += (y + 1) / 2;
        else
            tans += (y + z + 2) / 3;
    }
    return tans;
}

void solve()
{
    sort(mas.begin(), mas.end());
    if (mas[n - 1] > a + b + c)
    {
        ans = -1;
        return;
    }
    clr();

    if (c >= a + b)
    {
        sort(mas.begin(), mas.end());
        lb = upper_bound(mas.begin(), mas.end(), a + b) - mas.begin();
        int k = n - lb;
        ans += n - lb;
        for (; mas.size() > lb; mas.pop_back());
        n = mas.size();

        int x, y, z;
        x = upper_bound(mas.begin(), mas.end(), b) - mas.begin();
        y = upper_bound(mas.begin(), mas.end(), a) - mas.begin();
        z = y;
        y = x - y;
        x = n - x;
        
        tans = INF;

        for (int i(0); i <= min(k, x); ++i)
        {
            int t = k - i;
            if (y >= t)
                tans = min(tans, end(x - i, y - t, max(z - t, 0)));
            else
            {
                t = 2 * t - y;
                tans = min(tans, end(x - i, 0, max(z - t, 0)));
            }
        }

        ans += tans;
    }
    else
    {
        sort(mas.begin(), mas.end());
        lb = upper_bound(mas.begin(), mas.end(), c) - mas.begin();
        ub = lb;
        sort(mas.begin(), mas.end(), cmpc);
        ans += n - lb;
        for (; mas.size() > lb; mas.pop_back());
        for (int i(0); i < min(ub, n - lb); ++i)
            mas.pop_front();
        n = mas.size();

        sort(mas.begin(), mas.end());
        int x, y, z;
        x = upper_bound(mas.begin(), mas.end(), b) - mas.begin();
        y = upper_bound(mas.begin(), mas.end(), a) - mas.begin();
        z = y;
        y = x - y;
        x = n - x;
        ans += end(x, y, z);
    }
}

void output()
{
    cout << ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}