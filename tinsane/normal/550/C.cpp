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
    bool f(0);
    int dp;
    string s, k;
    cin >> s;
    for(long long i(0); i < 1000; i += 8)
    {
        k = to_string(i);
        dp = k.size() - 1;
        for(int j(s.size() - 1); j >= 0 && dp >= 0; --j)
        if(s[j] == k[dp])
            --dp;
        if(dp == -1)
        {
            cout << "YES\n" << k;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}