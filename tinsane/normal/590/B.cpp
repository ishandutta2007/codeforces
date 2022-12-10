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

#define mk make_pair

typedef pair<int, int> pii;

//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-9;
const int MAXN = 1e3 + 10;

bool deq(double a, double b)
{
    return abs(a - b) < eps;
}

bool dlesseq(double a, double b)
{
    return a < b || deq(a, b);
}

bool dless(double a, double b)
{
    return a < b && !deq(a, b);
}

struct Poi
{
    double x, y;
    Poi() : x(0), y(0) {}
    Poi (double x, double y) : x(x), y(y) {}
    Poi neg() const
    {
        return Poi(-x, -y);
    }
    Poi operator+ (const Poi& p) const
    {
        return Poi(x + p.x, y + p.y);
    }
    Poi operator- (const Poi& p) const
    {
        return Poi(x - p.x, y - p.y);
    }
    double operator* (const Poi& p) const
    {
        return (x * p.x + y * p.y);
    }
    double len() const
    {
        return sqrt(*this * *this);
    }
    Poi operator* (const double k) const
    {
        return Poi(x * k, y * k);
    }
};

double v, t, ans, was(0);
Poi chs, goal, bef, aft, g1;

void init()
{
    cin >> chs.x >> chs.y >> goal.x >> goal.y >> v >> t >> bef.x >> bef.y >> aft.x >> aft.y;
    goal = goal - chs;
}

double bs()
{
    double mi = 0, ma = t;
    while(ma - mi > eps)
    {
        double mid = (mi + ma) / 2;
        Poi g = goal + (bef * mid);
        if(dlesseq(g.len() / v, mid + was))
            ma = mid;
        else
            mi = mid;
    }
    return ma + was;
}

void solve()
{
    bef = bef.neg();
    g1 = goal + (bef * t);
    if(dlesseq(g1.len() / t, v))
    {
        ans = bs();
        return;
    }

    was = t;
    goal = goal + (bef * t);
    t = MAXLL;
    bef = aft.neg();
    ans = bs();
}

void output()
{
    cout << setprecision(9) << fixed << ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
}