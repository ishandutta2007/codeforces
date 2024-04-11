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
#include <algorithm>
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long w, m, mas[100];
    bool f(1);
    cin >> w >> m;
    if(w == 2)
    {
        cout << "YES";
        return 0;
    }
    for(int i(0); m && f; ++i)
    {
        mas[i] = m % w, m /= w;
        if(mas[i] == w - 1)
            ++m;
        else if(mas[i] > 1)
            f = 0;
    }
    if(f)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}