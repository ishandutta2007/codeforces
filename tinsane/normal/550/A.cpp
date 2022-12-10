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
const double eps = 1e-9;
const int MAXN = 1e3 + 10;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    bool f1, f2;
    cin >> s;
    f1 = f2 = 0;
    for(int i(0); i < s.size() - 1; ++i)
    if(!f1)
    {
        if(s[i] == 'A' && s[i + 1] == 'B')
            f1 = 1, ++i;
    }
    else
        if(s[i] == 'B' && s[i + 1] == 'A')
            f2 = 1;
    if(f1 && f2)
    {
        cout << "YES";
        return 0;
    }
    f1 = f2 = 0;
    for(int i(0); i < s.size() - 1; ++i)
    if(!f1)
    {
        if(s[i] == 'B' && s[i + 1] == 'A')
            f1 = 1, ++i;
    }
    else
        if(s[i] == 'A' && s[i + 1] == 'B')
            f2 = 1;
    if(f1 && f2)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}