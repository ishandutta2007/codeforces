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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;
const long long MANS = 25e8;

int n, res[MAXN], x, y, rsi(0);
vector<int> sqr[1001][1001];
long long sum(0);

void init()
{
    scanf("%d", &n);
    for(int i(0); i < n; ++i)
        scanf("%d%d", &x, &y), sqr[x / 1000][y / 1000].push_back(i + 1);
}

void solve()
{
    for(int i(0); i < 1001; ++i)
    {
        if(i & 1)
            for(int j(0); j < 1001; ++j)
            for(int k(0); k < sqr[i][j].size(); ++k)
                res[rsi++] = sqr[i][j][k];
        else
            for(int j(1000); j >= 0; --j)
            for(int k(0); k < sqr[i][j].size(); ++k)
                res[rsi++] = sqr[i][j][k];
    }
}

void output()
{
    for(int i(0); i < n; ++i)
        printf("%d ", res[i]);
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}