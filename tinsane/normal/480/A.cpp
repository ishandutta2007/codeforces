#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>
using namespace std;
//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:167772160")

int comp(const void * a, const void * b)
{
    pair<int,int>* f = (pair<int,int>*) a, *s = (pair<int,int>*) b;
    return (f->first != s->first ? f->first - s->first : f->second - s->second);
}

int main()
{
    pair<int,int> mas[5000];
    int n, ans(0);
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].first >> mas[i].second;
    qsort(mas, n, sizeof(pair<int,int>), comp);
    for(int i(0); i < n; ++i)
        ans = (mas[i].second >= ans ? mas[i].second : mas[i].first);
    cout << ans;
    return 0;
}