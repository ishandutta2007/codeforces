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
const int MAXN = (1 << 20) + 30;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, mas[200000];
    map<int, bool> ye;
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i], mas[i] -= n - i - 1;
    sort(mas, mas + n);
    for(int i(0); i < n - 1; ++i)
    if(mas[i] == mas[i + 1] || mas[i] + n - i - 1 < 0)
    {
        cout << ":(";
        return 0;
    }
    for(int i(0); i < n; ++i)
        cout << mas[i] + n - i - 1 << ' ';
    return 0;
}