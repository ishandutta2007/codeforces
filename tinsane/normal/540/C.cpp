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
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;
int n, m, r1, r2, c1, c2, wave[1001000], wsi(1);
char lvl[502][502], t;
bool was[502][502];

void tr(int x, int y)
{
    if(lvl[x + 1][y] == '.' && !was[x + 1][y])
    {
        was[x + 1][y] = 1;
        wave[wsi++] = (x + 1) * 1000 + y;
    }
    if(lvl[x - 1][y] == '.' && !was[x - 1][y])
    {
        was[x - 1][y] = 1;
        wave[wsi++] = (x - 1) * 1000 + y;
    }
    if(lvl[x][y + 1] == '.' && !was[x][y + 1])
    {
        was[x][y + 1] = 1;
        wave[wsi++] = x * 1000 + y + 1;
    }
    if(lvl[x][y - 1] == '.' && !was[x][y - 1])
    {
        was[x][y - 1] = 1;
        wave[wsi++] = x * 1000 + y - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        lvl[i][0] = lvl[i][m + 1] = 'X';
    for(int i(0); i < m; ++i)
        lvl[0][i] = lvl[n + 1][i] = 'X';
    for(int i(1); i <= n; ++i)
    for(int j(1); j <= m; ++j)
        cin >> lvl[i][j], was[i][j] = 0;
    cin >> r1 >> c1 >> r2 >> c2;
    t = lvl[r2][c2];
    lvl[r2][c2] = '.';
    if(r1 == r2 && c1 == c2)
    {
        if(lvl[r1 - 1][c1] == '.' || 
            lvl[r1 + 1][c1] == '.' || 
            lvl[r1][c1 + 1] == '.' ||
            lvl[r1][c1 - 1] == '.')
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }
    wave[0] = 1000 * r1 + c1;
    for(int i(0); i < wsi; ++i)
        tr(wave[i] / 1000, wave[i] % 1000);
    if(was[r2][c2])
    {
        if(t == 'X')
            cout << "YES";
        else
        {
            int cnt = 0;
            cnt += (lvl[r2][c2 - 1] == '.');
            cnt += (lvl[r2][c2 + 1] == '.');
            cnt += (lvl[r2 - 1][c2] == '.');
            cnt += (lvl[r2 + 1][c2] == '.');
            if(cnt >= 2 || (abs(r2 - r1) + abs(c2 - c1) == 1 && cnt == 1))
                cout << "YES";
            else
                cout << "NO";
        }
    }
    else
        cout << "NO";
    return 0;
}