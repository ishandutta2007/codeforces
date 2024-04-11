#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

const int N = 41;

char table[N][N];
int cnt[N][N][N][N];
int oneCnt[N][N][N][N];
int up[N][N];

int getCnt(int a, int b, int c, int d)
{
    if (b < 0 || c < 0 || d < 0)
        return 0;
    return cnt[a][b][c][d];
}

int main()
{
    
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf(" %s", table[i]);
        
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
        {
            if (table[i][s] == '0')
                up[i][s] = (i == 0 ? 1 : up[i - 1][s] + 1);
            else
                up[i][s] = 0;
        }
    
    
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < m; x++)
        {
            int curMax = N;
            for (int y = x; y < m; y++)
            {
                curMax = min(curMax, up[i][y]);
                if (curMax == 0)
                    break;
                for (int q = 1; q <= curMax; q++)
                    oneCnt[i][x][y][q] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < m; x++)
            for (int y = 0; y < m; y++)
                for (int h = 0; h <= n; h++)
                {
                    cnt[i][x][y][h] = getCnt(i, x - 1, y, h) + getCnt(i, x, y - 1, h) + getCnt(i, x, y, h - 1) - getCnt(i, x - 1, y - 1, h) - getCnt(i, x - 1, y, h - 1) - getCnt(i, x, y - 1, h - 1) + getCnt(i, x - 1, y - 1, h - 1) + oneCnt[i][x][y][h];
                }
    }
        
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--, b--, c--, d--;
        int ans = 0;
        for (int s = a; s <= c; s++)
        {   
            ans += cnt[s][d][d][s - a + 1] - (b == 0 ? 0 : cnt[s][b - 1][d][s - a + 1]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}