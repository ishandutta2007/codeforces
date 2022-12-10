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
    ios_base::sync_with_stdio(0);
    int n, a;
    bool f;
    vector<int> res;
    cin >> n;
    for(int i(0); i < n; ++i)
    {
        f = 0;
        for(int j(0); j < n; ++j)
            cin >> a, f |= (a == 3 || a == 1);
        if(!f)
            res.push_back(i + 1);
    }
    cout << res.size() << '\n';
    for(int i(0); i < res.size(); ++i)
        cout << res[i] << ' ';
    return 0;
}