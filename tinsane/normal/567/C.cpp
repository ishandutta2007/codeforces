#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
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
const double eps = 1e-11;
const int MAXN = 1e6 + 10;

map<int, long long> cnt, acnt;
int n, k, num;
long long res(0);

void init()
{
    cin >> n >> k;
}

void solve()
{
    for(int i(0); i < n; ++i)
    {
        cin >> num;
        ++cnt[num];
        if(k == 1 || num == 0)
        {
            res += (cnt[num] - 1) * (cnt[num] - 2)  / 2;
            continue;
        }
        if(num % k == 0)
            acnt[num] += cnt[num / k];
        if(num % k == 0 && num / k % k == 0)
            res += acnt[num / k];
    }
}

void output()
{
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}