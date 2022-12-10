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
    int num, pos;
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, mas[100], mip(0), map(0);
    cin >> n >> k;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i];
        if(mas[i] < mas[mip])
            mip = i;
        else if(mas[i] > mas[map])
            map = i;
    }
    if(mas[map] - mas[mip] > k)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i(0); i < n; ++i)
    {
        if(mas[i] == mas[mip])
        {
            for(int j(0); j < mas[mip]; ++j)
                cout << "1 ";
        }
        else
        {
            for(int j(0); j <= mas[mip]; ++j)
                cout << "1 ";
            for(int s(2); s <= mas[i] - mas[mip]; ++s)
                cout << s << ' ';
        }
        cout << '\n';
    }
    return 0;
}