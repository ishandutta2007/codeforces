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
    int n1, n2, last(-1), ln1, ln2, n3, lol(0);     
    string s;
    cin >> s;
    n1 = n2 = n3 = 0;
    for(int i(0); i < s.size(); ++i)
    {
        if(s[i] == '(')
            ++n1;
        else if(s[i] == ')')
            ++n2;
        else
        {
            ++n3;
            ++n2;
            last = i;
            ln1 = n1;
            ln2 = n2;
        }
        if(n2 > n1)
        {
            cout << -1;
            return 0;
        }
    }
    if((last == -1 && n1 != n2) || n1 - n2 + ln2 > ln1)
    {
        cout << -1;
        return 0;
    }
    lol = ln1 - (ln2 + n1 - n2);
    for(int i(last + 1); i < s.size(); ++i)
    {
        if(s[i] == '(')
            ++lol;
        else
            --lol;
        if(lol < 0)
        {
            cout << -1;
            return 0;
        }
    }
    if(lol)
    {
        cout << -1;
        return 0;
    }
    for(int i(1); i < n3; ++i)
        cout << "1\n";
    cout << n1 - n2 + 1;
    return 0;
}