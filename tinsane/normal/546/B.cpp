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
    ios_base::sync_with_stdio(0);
    int n, mas[3000], ans(0);
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    sort(mas, mas + n);
    for(int i(1); i < n; ++i)
        if(mas[i] <= mas[i - 1])
            ans += mas[i - 1] - mas[i] + 1, mas[i] = mas[i - 1] + 1;
    cout << ans;
    return 0;
}