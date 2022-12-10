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
    int n, w, mas[MAXN], x;
    double ans;
    cin >> n >> w;
    for(int i(0); i < n * 2; ++i)
        cin >> mas[i];
    sort(mas, mas + n * 2);
    ans = min(min(mas[0] * 1.0, mas[n] / 2.0) * 3 * n, w * 1.0);
    cout << setprecision(9) << fixed << ans;
    return 0;
}