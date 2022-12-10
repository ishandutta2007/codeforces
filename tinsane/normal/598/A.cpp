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
const double eps = 1e-9;
const int MAXN = 2e3 + 10;

long long n, res(0), p2(1);
int t;

void init()
{
    cin >> t;
}

void solve()
{
    while(t--)
    {
        cin >> n;
        res = (n + 1) * n / 2;
        p2 = 1;
        for(; p2 <= n; p2 *= 2)
            res -= p2 * 2;
        cout << res << '\n';
    }
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