#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

const int maxN = 1002;
bool a[maxN][maxN];
int m, n, k;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
    dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool black[8];

int main()
{
    //freopen("pixels.inp", "r", stdin);
    //freopen("pixels.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, k)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        fto(i, 0, 7) black[i] = a[x+dx[i]][y+dy[i]];
        if ((black[0] && black[1] && black[2]) || (black[2] && black[3] && black[4])
          ||(black[4] && black[5] && black[6]) ||(black[6] && black[7] && black[0]))
        {
            printf("%d", i);
            return 0;
        }
        a[x][y] = true;
    }
    printf("0");
}