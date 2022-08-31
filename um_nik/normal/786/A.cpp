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

const int N = 7010;
int n;
int a[2][N];
int m[2];
int ans[2][N];
int deg[2][N];
int q[N * 2][2];
int topQ;

void addQ(int x, int y)
{
    q[topQ][0] = x;
    q[topQ][1] = y;
    topQ++;
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int k = 0; k < 2; k++)
    {
        scanf("%d", &m[k]);
        for (int i = 0; i < m[k]; i++)
            scanf("%d", &a[k][i]);
        for (int i = 0; i < n; i++)
        {
            deg[k][i] = m[k];
            ans[k][i] = -1;
        }
        ans[k][0] = 0;
        addQ(0, k);
    }
    for (int p = 0; p < topQ; p++)
    {
        int x = q[p][0], k = q[p][1];
        if (ans[k][x] == 0)
        {
            for (int i = 0; i < m[k ^ 1]; i++)
            {
                int y = (x + n - a[k ^ 1][i]) % n;
                if (ans[k ^ 1][y] == -1)
                {
                    ans[k ^ 1][y] = 1;
                    addQ(y, k ^ 1);
                }
            }
        }
        else
        {
            for (int i = 0; i < m[k ^ 1]; i++)
            {
                int y = (x + n - a[k ^ 1][i]) % n;
                deg[k ^ 1][y]--;
                if (deg[k ^ 1][y] == 0 && ans[k ^ 1][y] == -1)
                {
                    ans[k ^ 1][y] = 0;
                    addQ(y, k ^ 1);
                }
            }
        }
    }
    for (int k = 0; k < 2; k++)
    {
        for (int i = 1; i < n; i++)
        {
            if (ans[k][i] == -1)
                printf("Loop ");
            else if (ans[k][i] == 0)
                printf("Lose ");
            else
                printf("Win ");
        }
        printf("\n");
    }

    return 0;
}