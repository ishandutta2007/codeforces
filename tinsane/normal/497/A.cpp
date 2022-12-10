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
    vector<int> cha;
    int n, m, cou(0);
    char lastc;
    bool alr[1000], f(0);
    string mas[1000];
    cin >> n >> m;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i];
        alr[i] = 0;
    }
    for(int j(0); j < m; ++j)
    {
        cha.clear();
        lastc = 'a' - 1;
        f = 0;
        for(int i(0); i < n; ++i)
        if(mas[i][j] >= lastc || alr[i])
        {
            if(mas[i][j] > lastc && !alr[i])
            {
                alr[i] = 1;
                cha.push_back(i);
            }
            lastc = mas[i][j];
        }
        else
        {
            ++cou;
            f = 1;
            break;
        }
        if(f)
            for(int j(0); j < cha.size(); ++j)
                alr[cha[j]] = 0;
    }
    cout << cou;
    return 0;
}