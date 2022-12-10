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
    int n, m, ans(0), mas[100][100], del[100][100];
    string s[100];
    cin >> n >> m;
    for(int i(0); i < n; ++i)
    {
        cin >> s[i];
        for(int j(0); j < m; ++j)
            mas[i][j] = (s[i][j] == 'W') ? 1 : -1, del[i][j] = 0;
    }
    for(int i(n - 1); i >= 0; --i)
    for(int j(m - 1); j >= 0; --j)
    {
        mas[i][j] += del[i][j];
        if(mas[i][j])
        {
            ++ans;
            for(int k(i); k >= 0; --k)
                del[k][j] -= mas[i][j];
        }
        if(j)
            del[i][j - 1] += del[i][j];
    }
    cout << ans;
    return 0;
}