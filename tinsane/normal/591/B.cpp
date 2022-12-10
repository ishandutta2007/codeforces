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
#include <cassert>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

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
const int MODUL = 1000000007;
const int MAXINT = 1e9 + 2;
const ll MAXLL = 2e18 + 2;
const double eps = 1e-9;

const int N = 2e5 + 10;
const int ALP = 257;
string s;
int n, m;
char a, b, sw[ALP];

void init()
{
    cin >> n >> m >> s;
    for (int i(0); i < ALP; ++i)
        sw[i] = i;
}

void solve()
{
    for (int i(0); i < m; ++i)
    {
        cin >> a >> b;
        int f, s;
        for (int j(0); j < ALP; ++j)
        {
            if (sw[j] == a)
                f = j;
            if (sw[j] == b)
                s = j;
        }
        swap(sw[f], sw[s]);
    }
    for (int i(0); i < n; ++i)
        s[i] = sw[s[i]];
}

void output()
{
    cout << s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}