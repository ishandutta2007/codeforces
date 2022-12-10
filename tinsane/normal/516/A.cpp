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

#pragma comment(linker, "/STACK:1677721600")

int main()
{
    ios_base::sync_with_stdio(0);
    int n, cou[10];
    char c;
    cin >> n;
    for(int i(0); i < 10; ++i)
        cou[i] = 0;
    for(int i(0); i < n; ++i)
    {
        cin >> c;
        ++cou[c - '0'];
    }
    for(;cou[4];--cou[4], ++cou[2], ++cou[2], ++cou[3]);
    for(;cou[6];--cou[6], ++cou[5], ++cou[3]);
    for(;cou[8];--cou[8], ++cou[7], ++cou[2], ++cou[2], ++cou[2]);
    for(;cou[9];--cou[9], ++cou[2], ++cou[3], ++cou[3], ++cou[7]);
    for(int i(9); i >= 2; --i)
        for(;cou[i];cout << i, --cou[i]);
    return 0;
}