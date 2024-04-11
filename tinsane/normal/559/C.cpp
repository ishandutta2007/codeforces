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

long long fact[MAXN], res(0), rfact[MAXN];

long long bpow(long long x, long long p)
{
    return (p == 0 ? 1 : (p & 1) ? (x * bpow(x * x % MODUL, p / 2) % MODUL) : bpow(x * x % MODUL, p / 2));
}

long long cnk(int n, int k)
{
    return (fact[n] * rfact[k] % MODUL * rfact[n - k] % MODUL);
}

struct poi
{
    int x, y;
    long long val;
} mas[2010];

bool comp(poi f, poi s)
{
    return (f.x == s.x ? f.y < s.y : f.x < s.x);
}

int h, w, n;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    fact[0] = 1;
    rfact[0] = 1;
    for(int i(1); i < MAXN; ++i)
        fact[i] = (fact[i - 1] * i) % MODUL, rfact[i] = bpow(fact[i], MODUL - 2);
    cin >> h >> w >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].x >> mas[i].y;
    res = cnk(h + w - 2, h - 1);
    sort(mas, mas + n, comp);
    for(int i(0); i < n; ++i)
    {
        mas[i].val = cnk(mas[i].x + mas[i].y - 2, mas[i].x - 1);
        for(int j(0); j < i; ++j)
        if(mas[j].x <= mas[i].x && mas[j].y <= mas[i].y)
            mas[i].val = (MODUL + mas[i].val - mas[j].val * cnk(mas[i].x - mas[j].x + mas[i].y - mas[j].y, mas[i].x - mas[j].x) % MODUL) % MODUL;
        res = (MODUL + res - mas[i].val * cnk(h - mas[i].x + w - mas[i].y, h - mas[i].x) % MODUL) % MODUL;
    }
    cout << res;
    return 0;
}