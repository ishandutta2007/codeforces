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
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 2e5 + 10;
const int MAXM = 1e6 + 10;

int n, aft[MAXN], bef[MAXN], qu[MAXN], rbef[MAXM], raft[MAXM];

void init()
{
    for(int i(0); i < MAXM; ++i)
        rbef[i] = raft[i] = -1;
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> bef[i] >> aft[i], rbef[bef[i]] = i, raft[aft[i]] = i;
}

void solve()
{
    for(int i(0), j(rbef[0]); i < n; ++++i, j = rbef[aft[j]])
        qu[i] = j;
    int k(0);
    for(; k < n; ++k)
    if(bef[k] && raft[bef[k]] == -1)
        break;
    for(int i(1), j(k); i < n; ++++i, j = rbef[aft[j]])
        qu[i] = j;
}

void output()
{
    for(int i(1); i < n; ++i)
        cout << bef[qu[i]] << ' ';
    cout << aft[qu[n - 2]];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}