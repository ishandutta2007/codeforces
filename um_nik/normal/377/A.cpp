#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

string s[510];
int n, m, k;
bool u[510][510];

void Print()
{
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
    return;
}

void dfs(int x, int y)
{
    u[x][y] = true;
    if (x > 0)
    {
        if (s[x - 1][y] == '.' && !u[x - 1][y])
            dfs(x - 1, y);
    }
    if (x < n - 1)
    {
        if (s[x + 1][y] == '.' && !u[x + 1][y])
            dfs(x + 1, y);
    }
    if (y > 0)
    {
        if (s[x][y - 1] == '.' && !u[x][y - 1])
            dfs(x, y - 1);
    }
    if (y < m - 1)
    {
        if (s[x][y + 1] == '.' && !u[x][y + 1])
            dfs(x, y + 1);
    }
    if (k > 0)
    {
        s[x][y] = 'X';
        k--;
    }
    return;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                dfs(i, j);
                Print();
                return 0;
            }
        }
    }
    return 0;
}