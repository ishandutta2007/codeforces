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
    string s;
    int ans(0);
    cin >> ans >> s;
    ans = 0;
    for(int i(0); i < s.size(); ++i)
    if(s[i] == '1')
        ++ans;
    else
        --ans;
    cout << abs(ans);
    return 0;
}