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
const int MAXN = 2e5 + 10;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, mas[1000];
    bool f(0);
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    for(int i(-2); i < n; ++i)
    {
        f = 1;
        for(int j(1); j < n; ++j)
            f &= (mas[j] == mas[j - 1] + 1);
        if(f)
        {
            cout << "Yes";
            return 0;
        }
        for(int j(0); j < n; ++j)
        if(j & 1)
            mas[j] = (mas[j] + n - 1) % n;
        else
            mas[j] = (mas[j] + 1) % n;
    }
    cout << "No";
    return 0;
}