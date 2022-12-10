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
    int l, r;
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    double ans(0), tans, tans2, add;
    node mas[5];
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].l >> mas[i].r;
    for(int pri(1); pri < 10001; ++pri)
    for(int i(0); i < n; ++i)
    {

        if(mas[i].r < pri)
            continue;
        if(mas[i].l > pri)
            tans = pri;
        else
            tans = pri * (mas[i].r - pri)  / (mas[i].r - mas[i].l + 1.0);

        for(int j(0); j < n; ++j)
        {
            if(j == i || mas[j].r < pri || mas[j].l > pri)
                continue;
            tans2 = tans / (mas[j].r - mas[j].l + 1);
            for(int k(0); k < n; ++k)
            {
                if(k == i || k == j)
                    continue;
                if(mas[k].l > pri)
                {
                    tans2 = 0;
                    break;
                }
                if(k < j)
                {
                    if(mas[k].r >= pri)
                        tans2 *= (pri - mas[k].l) / (mas[k].r - mas[k].l + 1.0);
                }
                else
                    tans2 *= (MIN(mas[k].r, pri) - mas[k].l + 1.0) / (mas[k].r - mas[k].l + 1.0);
            }
            ans += tans2;
        }
        
        if(mas[i].l  > pri)
            continue;
        tans = pri / (mas[i].r - mas[i].l + 1.0);

        for(int j(0); j < n; ++j)
        {
            if(j <= i || mas[j].r < pri || mas[j].l > pri)
                continue;
            tans2 = tans / (mas[j].r - mas[j].l + 1);
            for(int k(0); k < n; ++k)
            {
                if(k == i || k == j)
                    continue;
                if(mas[k].l > pri)
                {
                    tans2 = 0;
                    break;
                }
                if(k < j)
                {
                    if(pri <= mas[k].r)
                        tans2 *= (pri - mas[k].l) / (mas[k].r - mas[k].l + 1.0);
                }
                else
                    tans2 *= (MIN(mas[k].r, pri) - mas[k].l + 1.0) / (mas[k].r - mas[k].l + 1.0);
            }
            ans += tans2;
        }
    }
    cout << setprecision(9) << fixed << ans;
    return 0;
}