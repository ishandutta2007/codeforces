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

//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, cnt[MAXN], x, ans(0);

void init()
{
    cin >> n;
    for(int i(0); i < MAXN; ++i)
        cnt[i] = 0;
    for(int i(0); i < n; ++i)
    {
        cin >> x;
        ++cnt[x];
    }
}

void solve()
{
    for(int i(0); i < MAXN; ++i)
        cnt[i + 1] += cnt[i] / 2, ans += (cnt[i] & 1);
}

void output()
{
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
}