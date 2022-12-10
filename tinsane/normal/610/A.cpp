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

int n, ans(0);

void init()
{
    cin >> n;
}

void solve()
{
    if (n % 2 == 1)
        return;
    n /= 2;
    ans = (n - 1) / 2;
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