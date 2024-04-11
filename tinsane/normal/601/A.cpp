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
const double eps = 1e-8;
const int MAXN = 4e2 + 10;

int n, m, a, b, ans(-1), ti[MAXN], wave[MAXN], wsi(1);
char matr[MAXN][MAXN];

void init()
{
    cin >> n >> m;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> b;
        --a, --b;
        matr[a][b] = matr[b][a] = 1;
    }
}

void solve()
{
    if(m == 0 || m == n * (n - 1) / 2)
        return;
    if (matr[0][n - 1])
    {
        for(int i(0); i < n; ++i)
        for(int j(0); j < n; ++j)
            matr[i][j] = !matr[i][j];
    }
    ti[0] = 1;
    wave[0] = 0;
    for(int i(0); i < wsi; ++i)
    {
        int v = wave[i];
        for(int j(0); j < n; ++j)
        if(matr[v][j] && !ti[j])
        {
            wave[wsi++] = j;
            ti[j] = ti[v] + 1;
        }
    }
    ans = ti[n - 1] - 1;
}

void output()
{
    cout << ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
 }