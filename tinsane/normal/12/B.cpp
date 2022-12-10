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

int main()
{
    bool fir = 0;
    string m, best;
    char min('9' + 1);
    cin >> best >> m;
    for(int i(0); i < best.size(); ++i)
        if(best[i] != '0')
            min = MIN(min, best[i]);
    for(int i(0); i < best.size(); ++i)
        if(best[i] == '0')
            best[i] = '2';
        else if(best[i] == min && !fir)
        {
            fir = 1;
            best[i] = '1';
        }
        else
            best[i] += 2;
    sort(best.begin(), best.end());
    if(min != '9' + 1)
        best[0] = min;
    else
        best[0] = '0';
    for(int i(1); i < best.size(); ++i)
        if(best[i] == '2')
            best[i] = '0';
        else
            best[i] -= 2;
    if(best != m)
        cout << "WRONG_ANSWER";
    else
        cout << "OK";
    return 0;
}