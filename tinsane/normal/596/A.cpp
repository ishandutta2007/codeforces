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

struct point
{
    int x, y;
    point() {};
    point(int x, int y) : x(x), y(y) {};

    void scan()
    {
        cin >> x >> y;
    }
};

point mas[4];
int n;

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        mas[i].scan();
}

void solve()
{
    int x1, x2, y1, y2; 
    x1 = x2 = mas[0].x;
    y1 = y2 = mas[0].y;
    for(int i(0); i < n; ++i)
        x1 = min(x1, mas[i].x), x2 = max(x2, mas[i].x), y1 = min(y1, mas[i].y), y2 = max(y2,  mas[i].y);
    if((x2 - x1) * (y2 - y1) > 0)
        cout << (x2 - x1) * (y2 - y1);
    else
        cout << -1;
}

void output()
{
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
 }