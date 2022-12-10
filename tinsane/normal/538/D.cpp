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
const int MAXN = 5e4 + 10;

struct poi
{
    int x, y;
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, dx, dy, x, y;
    char mas[50][50], res[100][100];
    bool f;
    poi tmp;
    vector<poi> fig;
    cin >> n;
    res[n - 1][n - 1] = 'o';
    for(int i(0); i < n; ++i)
    for(int j(0); j < n; ++j)
    {
        cin >> mas[i][j];
        if(mas[i][j] == 'o')
            tmp.x = i, tmp.y = j, fig.push_back(tmp);
    }
    for(int i(0); i < 2 * n - 1; ++i)
    for(int j(0); j < 2 * n - 1; ++j)
    {
        dx = i - n + 1;
        dy = j - n + 1;
        if(dx == 0 && dy == 0)
            continue;
        f = 1;
        for(int k(0); k < fig.size(); ++k)
        {
            x = fig[k].x + dx;
            y = fig[k].y + dy;
            if(x >= 0 && x < n && y >= 0 && y < n && mas[x][y] == '.')
            {
                f = 0;
                break;
            }
        }
        if(f)
        {
            res[i][j] = 'x';
            for(int k(0); k < fig.size(); ++k)
            {
                x = fig[k].x + dx;
                y = fig[k].y + dy;
                if(x >= 0 && x < n && y >= 0 && y < n && mas[x][y] == 'x')
                    mas[x][y] = 'X';
            }
        }
        else
            res[i][j] = '.';
    }
    for(int i(0); i < n; ++i)
    for(int j(0); j < n; ++j)
    if(mas[i][j] == 'x')
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i(0); i < n * 2 - 1; ++i, cout << '\n')
    for(int j(0); j < n * 2 - 1; ++j)
        cout << res[i][j];
    return 0;
}