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
#include <unordered_map>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

#define mk make_pair

typedef pair<int, int> pii;
typedef long long ll;

//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-9;
const int MAXN = 1e5 + 10;

struct poi
{
    int x, y;

    poi() : x(0), y(0) {}
    poi(int x, int y) : x(x), y(y) {}

    bool operator< (const poi& p) const
    {
        return (y - x != p.y - p.x ? y - x < p.y - p.x : x != p.x ? x < p.x : y < p.y);
    }
};

bool win(1);
int n, w[MAXN], mx, my;
set<poi> s, used;
poi mas[MAXN];
set<poi>::iterator it;

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].x >> mas[i].y, mx = max(mx, mas[i].x), my = max(my, mas[i].y);
    for(int i(0); i < n; ++i)
        cin >> w[i];
    ++mx, ++my;
    s.insert(poi(0, 0));
}

void check(int x, int y)
{
    if(x >= mx || y >= my)
        return;
    if((x == 0 || used.find(poi(x - 1, y)) != used.end()) && (y == 0 || used.find(poi(x, y - 1)) != used.end()))
        s.insert(poi(x, y));
}

void solve()
{
    for(int i(0); i < n; ++i)
    {
        it = s.lower_bound(poi(0, w[i]));
        if (it == s.end() || it->y - it->x != w[i])
        {
            win = 0;
            return;
        }
        used.insert(*it);
        mas[i] = *it;
        check(it->x + 1, it->y);
        check(it->x, it->y + 1);
        s.erase(it);
    }
}

void output()
{
    if(win)
    {
        cout << "YES\n";
        for(int i(0); i < n; ++i)
            cout << mas[i].x << ' ' << mas[i].y << '\n';
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
 }