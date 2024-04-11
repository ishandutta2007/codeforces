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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
typedef long long ll;
typedef pair<int, int> pii;

const double PI = 3.14159265358979323846;
const int MODUL = 1000000007;
const int MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

int a, b, c;

void init()
{
    cin >> a >> b >> c;
}

void solve()
{
}

void output()
{
    cout << min(min((a + c) * 2, (b + c) * 2), min(a + b + c, (a + b) * 2));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}