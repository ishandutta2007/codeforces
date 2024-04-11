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
const int MAXN = 1e4 + 10;

struct Node
{
    int num, ti;

    bool operator< (Node s)
    {
        return ti < s.ti;
    }
} mas[100];

int n, k, cnt(0);

void init()
{
    cin >> n >> k;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i].ti;
        mas[i].num = i + 1;
    }
    sort(mas, mas + n);
}

void solve()
{
}

void output()
{
    cnt = (mas[0].ti > k ? 0 : n);
    for(int i(1); i < n; ++i)
    {
        mas[i].ti += mas[i - 1].ti;
        if(cnt == n && mas[i].ti > k)
            cnt = i;
    }
    cout << cnt << '\n';
    for(int i(0); i < cnt; ++i)
        cout << mas[i].num << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}