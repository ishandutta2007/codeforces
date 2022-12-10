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

int n, x;
multiset<int> mas, nmas;

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> x, mas.insert(x), nmas.insert(x);
}

void solve()
{
    for(int i(1); i < n; ++i)
        cin >> x, mas.erase(mas.find(x));
    cout << *mas.begin() << '\n';
    nmas.erase(nmas.find(*mas.begin()));
    for(int i(2); i < n; ++i)
        cin >> x, nmas.erase(nmas.find(x));
    cout << *nmas.begin();
}

void output()
{
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}