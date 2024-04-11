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
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

#pragma comment(linker, "/STACK:1677721600")

struct man
{
    long long a;
    vector<int> lower;
};

int n, x, t;
man mas[200001];

long long dfs(int v)
{
    long long res(0), mi(0);
    if(mas[v].lower.size() & 1) mi = MAXINT;
    for(int i(0); i < mas[v].lower.size(); ++i)
        res += dfs(mas[v].lower[i]), res += mas[mas[v].lower[i]].a, mi = min(mi, mas[mas[v].lower[i]].a);
    if(mi > mas[v].a)
        mas[v].a = mi;
    return res - mi;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    ++n;
    for(int i(1); i < n; ++i)
    {
        cin >> t >> mas[i].a;
        if(t > 0)
            mas[t].lower.push_back(i);
        else
            x = i;
    }
    cout << dfs(x) + mas[x].a;
    return 0;
}