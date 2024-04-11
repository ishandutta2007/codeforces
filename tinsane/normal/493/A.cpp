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
    int n, fols[2][101];
    string s[2];
    cin >> s[0] >> s[1] >> n;
    for(int i(0); i < 101; ++i)
        fols[0][i] = fols[1][i] = 0;
    for(; n--;)
    {
        char a, b;
        int t, m;
        cin >> t >> a >> m >> b;
        if(a == 'h')
            a = 0;
        else
            a = 1;
        if(fols[a][m] != 2)
            if(b == 'r' || fols[a][m] == 1)
            {
                fols[a][m] = 2;
                cout << s[a] << ' ' << m << ' ' << t << '\n';
            }
            else
                fols[a][m] = 1;
    }
    return 0;
}