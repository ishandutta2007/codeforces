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
const int P = 1000000007;
const int INF = 1e9 + 2;
const ll LINF = 2e18 + 2;
const double eps = 1e-9;

const int N = 5e2 + 10;
int n, m, q, dp1[N][N], dp2[N][N], ans;
string mas[N];

void init()
{
    cin >> n >> m;
    for (int i(0); i < n; ++i)
        cin >> mas[i];
    cin >> q;
    for (int i(0); i < n; ++i)
    for (int j(0); j < m; ++j)
    {
        dp1[i + 1][j + 1] = dp1[i + 1][j] + dp1[i][j + 1] - dp1[i][j] + (mas[i][j] == '.' && i + 1 < n && mas[i + 1][j] == '.');
        dp2[i + 1][j + 1] = dp2[i + 1][j] + dp2[i][j + 1] - dp2[i][j] + (mas[i][j] == '.' && j + 1 < m && mas[i][j + 1] == '.');
    }
}

void solve()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ans = dp1[x2 - 1][y2] + dp1[x1 - 1][y1 - 1] - dp1[x2 - 1][y1 - 1] - dp1[x1 - 1][y2];
    ans += dp2[x2][y2 - 1] + dp2[x1 - 1][y1 - 1] - dp2[x2][y1 - 1] - dp2[x1 - 1][y2 - 1];
}

void output()
{
    cout << ans << '\n';
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    while (q--)
    {
        solve();
        output();
    }
    return 0;
}