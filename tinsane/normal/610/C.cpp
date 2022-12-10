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
const long long P = 1e9 + 7;
const long long MAXINT = 1e9 + 10;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;

const int N = 1e3 + 25;
int n, k;
char mas[N][N];

void init()
{
    cin >> k;
    n = (1 << k);
    mas[0][0] = 1;
}

void solve()
{
    for(int t(0); t < k; ++t)
    {
        int si = (1 << t);
        for(int i(0); i < si; ++i)
            for(int j(0); j < si; ++j)
                mas[si + i][j] = mas[si + i][si + j] = mas[i][j],
                mas[i][si + j] = !mas[i][j];
    }
}

void output()
{
    for(int i(0); i < n; ++i, cout << '\n')
        for(int j(0); j < n; ++j)
            if(mas[i][j])
                cout << '+';
            else
                cout << '*';
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