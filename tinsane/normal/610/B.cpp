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

const int N = 2e5 + 10;
int n, mas[N], mi(MAXINT);
ll ans;

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i], mi = min(mi, mas[i]);
}

void solve()
{
    int lmi = n - 1, tmp, ma(0);
    for(; mas[lmi] != mi; --lmi);
    tmp = lmi;
    for(int i(lmi - 1); i >= 0; --i)
    if (mas[i] == mi)
    {
        ma = max(ma, lmi - i - 1);
        lmi = i;
    }
    ma = max(ma, lmi + n - tmp - 1);

    ans = 1LL * mi * n + ma;
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