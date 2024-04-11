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

int n, mas[101], r, ins[MAXN], cnt(0);
char c;

void init()
{
    cin >> n;
    for(int i(0); i < 101; ++i)
        mas[i] = 0;
    for(int i(1); i < MAXN; ++i)
        ins[i] = -1;
}

void solve()
{
    for(int i(0); i < n; ++i)
    {
        cin >> c >> r;
        if(c == '+')
            ins[r] = i + 1, ++cnt;
        else
        {
            if(ins[r] == -1)
            {
                for(int j(0); j <= i; ++j)
                    ++mas[j];
            }
            else
            {
                for(int j(ins[r]); j <= i; ++j)
                    ++mas[j];
                ins[r] = -1;
                --cnt;
            }
        }
    }
    for(int i(1); i < MAXN; ++i)
    if(ins[i] != -1)
        for(int j(ins[i]); j < 101; ++j)
            ++mas[j];
    r = cnt;
    for(int i(0); i < 101; ++i)
        r = max(r, mas[i]);
}

void output()
{
    cout << r;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}