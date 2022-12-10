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

string mas[8];
int cnt(0), wei[256];

void init()
{
    for(int i(0); i < 8; ++i)
        cin >> mas[i];
    for(int i(0); i < 256; ++i)
        wei[i] = 0;
    wei['Q'] = 9;
    wei['R'] = 5;
    wei['B'] = wei['N'] = 3;
    wei['P'] = 1;
    wei['q'] = -9;
    wei['r'] = -5;
    wei['b'] = wei['n'] = -3;
    wei['p'] = -1;
}

void solve()
{
    for(int i(0); i < 8; ++i)
    for(int j(0); j < 8; ++j)
        cnt += wei[mas[i][j]];
}

void output()
{
    if(cnt > 0)
        cout << "White";
    else if(cnt == 0)
        cout << "Draw";
    else
        cout << "Black";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}