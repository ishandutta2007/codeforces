#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 1000;
const int M = (int)1e6;

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
char table[N][N];
bool used[N][N];
pii topS[M];
int indT = 0;
int n, m;

bool check(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int x, int y)
{
    used[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + DX[i];
        int ny = y + DY[i];
        if (check(nx, ny) && !used[nx][ny] && table[nx][ny] == '.')
            dfs(nx, ny);
    }
    topS[indT++] = mp(x, y);
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
                
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
            scanf(" %c", &table[i][s]);

    pii st;       
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
        {
            if (table[i][s] == '.')
                st = mp(i, s);

        }                                   


    dfs(st.X, st.Y);

    for (int i = 0; i < k; i++)
    {
        table[topS[i].X][topS[i].Y] = 'X';
    }
    for (int i = 0; i < n; i++, puts(""))
        for (int s = 0; s < m; s++)
            printf("%c", table[i][s]);

    return 0;
}