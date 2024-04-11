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
const int MAXN = 1e5 + 10;

int n, s, a, b;
char c;
map<int, int> buy, sale;
map<int, int>::iterator it;

void init()
{
    cin >> n >> s;
    for(int i(0); i < n; ++i)
    {
        cin >> c >> a >> b;
        if(c == 'B')
            buy[a] += b;
        else
            sale[a] += b;
    }
}

void solve()
{
}

void output()
{
    int i;
    if(sale.size())
    {
        it = sale.end();
        --it;
        for(int i(s); i < sale.size(); ++i)
            --it;

        for(; it != sale.begin(); --it)
            cout << "S " << it->first << ' ' << it->second << '\n';
        cout << "S " << sale.begin()->first << ' ' << sale.begin()->second << '\n';
    }
    if(buy.size())
    {
        for(i = 0, it = buy.end(), --it; i < s && it != buy.begin(); ++i, --it)
            cout << "B " << it->first << ' ' << it->second << '\n';
        if(buy.size() <= s)
            cout << "B " << buy.begin()->first << ' ' << buy.begin()->second << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}