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
string a, b;

struct sub
{
    int f, s;
};
sub x, y;
int tlen, be, en;
long long ha[MAXN], hb[MAXN];

bool eq(sub& x, sub& y)
{
    if((x.s - x.f + 1) & 1)
        return ha[x.f / tlen] == hb[y.f / tlen];
    sub x1, x2, y1, y2;
    x1.f = x.f, x1.s = ((x.f + x.s) / 2), x2.f = (x.f + x.s) / 2 + 1, x2.s = x.s;
    y1.f = y.f, y1.s = ((y.f + y.s) / 2), y2.f = (y.f + y.s) / 2 + 1, y2.s = y.s;
    if(rand() & 1)
        return (eq(x1, y1) && eq(x2, y2)) || (eq(x1, y2) && eq(x2, y1));
    else
        return ((eq(x1, y2) && eq(x2, y1) || eq(x1, y1) && eq(x2, y2)));
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    tlen = a.size();
    for(;!(tlen & 1); tlen >>= 1);
    be = 0, en = tlen;
    for(int i(0); be < a.size(); ++i)
    {
        ha[i] = hb[i] = 0;
        for(int j(be); j < en; ++j)
        {
            ha[i] = (ha[i] * 28 + a[j] - 'a') % MODUL;
            hb[i] = (hb[i] * 28 + b[j] - 'a') % MODUL;
        }
        be += tlen, en += tlen;
    }
    x.f = y.f = 0, x.s = y.s = a.size() - 1;
    if(eq(x, y))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}