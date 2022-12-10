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

int n, ans;
const int mons[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string a, b;

void init()
{
    cin >> n >> a >> b;
}

void solve()
{
    if (b == "month")
    {
        for (int i(0); i < 12; ++i)
            ans += mons[i] >= n;
    }
    else
    {
        if (n == 6 || n == 5)
            ans = 53;
        else
            ans = 52;
    }
}

void output()
{
    cout << ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}