#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = 10000;
const int N = 77;
int n, m, k;
int dp[N][N][N][2];
int a[N];
int b[N];
int c[N];

void read()
{
    string s;
    cin >> s >> s;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == 'V')
            a[n++] = i;
        else if (s[i] == 'K')
            b[m++] = i;
        else
            c[k++] = i;
    }
    return;
}

int cost(int x, int y, int z, int p)
{
    int val;
    if (p == 0)
        val = a[x];
    else if (p == 1)
        val = b[y];
    else
        val = c[z];
    int res = 0;
    if (p != 0)
        res += max((int)(lower_bound(a, a + n, val) - a) - x, 0);
    if (p != 1)
        res += max((int)(lower_bound(b, b + m, val) - b) - y, 0);
    if (p != 2)
        res += max((int)(lower_bound(c, c + k, val) - c) - z, 0);
    return res;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int h = 0; h <= k; h++)
                for (int z = 0; z < 2; z++)
                    dp[i][j][h][z] = INF;
    dp[0][0][0][1] = 0;


    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int h = 0; h <= k; h++)
            {
                if (i + j + h == n + m + k) continue;
                for (int x = 0; x < 2; x++)
                {
                    if (dp[i][j][h][x] == INF) continue;
                    for (int y = 0; y < 3; y++)
                    {
                        if (x == 0 && y == 1) continue;
                        int ni = i, nj = j, nh = h;
                        if (y == 0)
                            ni++;
                        else if (y == 1)
                            nj++;
                        else
                            nh++;
                        if (ni > n || nj > m || nh > k) continue;
                        dp[ni][nj][nh][min(y, 1)] = min(dp[ni][nj][nh][min(y, 1)], dp[i][j][h][x] + cost(i, j, h, y));
                    }
                }
            }
    printf("%d\n", min(dp[n][m][k][0], dp[n][m][k][1]));

    return 0;
}