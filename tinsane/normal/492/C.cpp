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
#include <list>
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

struct node
{
    long long cou, cost;
};
node mas[100000];

int comp(const void* a, const void* b)
{
    return ((node*)a)->cost - ((node*)b)->cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    long long r, av, n, is(0), ans(0);
    cin >> n >> r >> av;
    av *= n;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i].cou >> mas[i].cost;
        is += mas[i].cou;
        mas[i].cou = r - mas[i].cou;
    }
    if(is >= av)
    {
        cout << 0;
        return 0;
    }
    qsort(mas, n, sizeof(node), comp);
    for(int i(0); i < n; ++i)
    {
        if(mas[i].cou + is < av)
        {
            is += mas[i].cou;
            ans += mas[i].cou * mas[i].cost;
        }
        else
        {
            ans += mas[i].cost * (av - is);
            break;
        }
    }
    cout << ans;
    return 0;
}