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

long long gcd(long long a, long long b)
{
    return a % b ? gcd(b, a % b) : b;
}

struct poi
{
    long long x, y;
};

struct line
{
    long long a, b, c;

    line(){}
    line(poi f, poi s)
    {
        a = f.y - s.y;
        b = s.x - f.x;
        c = f.x * s.y - f.y * s.x;
        if(b != 0)
        {
            long long g = gcd(a, b);
            g = gcd(c, g);
            a /= g, b /= g, c /= g;
        }
        else
        {
            long long g = gcd(c, a);
            a /= g, c /= g;
        }
        if(b < 0)
            a = -a, b = -b, c = -c;
    }
};

struct comp
{
    bool operator() (line f, line s)
    {
        return (f.a == s.a ? f.b == s.b ? f.c < s.c : f.b < s.b : f.a < s.a);
    }
};

poi mas[2000];
map<line, long long, comp> cnt;
long long n, ans(0);

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i].x >> mas[i].y;
        for(int j(0); j < i; ++j)
            ++cnt[line(mas[i], mas[j])];
    }
    ans = n * (n - 1) * (n - 2);
    for(map<line, long long, comp>::iterator it = cnt.begin(); it != cnt.end(); ++it)
    {
        long long x = sqrt(it->second * 2.0) + 1;
        ans -= x * (x - 1) * (x - 2);
    }
    cout << ans / 6;
    return 0;
}