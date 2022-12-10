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
#include <unordered_set>
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e4 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    string s, t("CODEFORCES");
    int n, m, pt(0), qt;
    cin >> s;
    n = s.size();
    m = t.size();
    if(n < m)
    {
        cout << "NO";
        return 0;
    }
    qt = m - 1;
    for(;pt < m && s[pt] == t[pt];++pt);
    for(;qt >= 0 && s[qt + n - m] == t[qt]; --qt);
    if(qt <= pt - 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}