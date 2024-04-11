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
    int n, a, who(0);
    long long res(0);
    queue<int> fir, sec;
    cin >> n;
    for(;--n;)
    {
        cin >> a;
        res += a;
        if(a > 0)
            fir.push(a);
        else
        {
            a = -a;
            sec.push(a);
        }
    }
    cin >> a;
    res += a;
    if(a > 0)
    {
        fir.push(a);
        who = 1;
    }
    else
    {
        a = -a;
        sec.push(a);
        who = 2;
    }
    if(res)
    {
        if(res > 0)
            cout << "first";
        else
            cout << "second";
        return 0;
    }
    for(; sec.size() && fir.size() && sec.front() == fir.front(); sec.pop(), fir.pop());
    if(sec.size() || fir.size())
    {
        if(sec.size() && fir.size())
        {
            if(sec.front() > fir.front())
                cout << "second";
            else
                cout << "first";
        }
        else
        {
            if(sec.size())
                cout << "second";
            else
                cout << "first";
        }
    }
    else
        if(who == 1)
            cout << "first";
        else
            cout << "second";
    return 0;
}