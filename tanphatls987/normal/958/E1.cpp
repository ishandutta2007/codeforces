#include <cstdio>
#include <cstdlib>

#define long long long

struct TPoint { long x, y; } a[12], b[12];
bool ccw(TPoint a, TPoint b, TPoint c) { return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0; }

int n, m;
bool chk[11][11][11][11];

bool Cut(TPoint a, TPoint b, TPoint c, TPoint d)
{
    return ccw(a, c, b) != ccw(a, d, b) && ccw(c, a, d) != ccw(c, b, d);
}

int mat[11];
void Recur(int idx)
{
    if (idx == n + 1)
    {
        printf("Yes");
        exit(0);
    }

    for (int i = 1; i <= n; ++i)
        if (!mat[i])
        {
            bool safe = true;
            for (int j = 1; safe && j < idx; ++j)
                if (chk[idx][i][j][mat[j]]) safe = false;

            if (safe)
            {
                mat[idx] = i;
                Recur(idx + 1);
            }

            mat[i] = 0;
        }
}

int main()
{
    scanf("%d %d", &n, &m);
    if (n != m)
    {
        printf("No");
        return 0;
    }
//    for (int i = 1; i <= n; ++i) scanf("%lld %lld", &a[i].x, &a[i].y);
//    for (int i = 1; i <= n; ++i) scanf("%lld %lld", &b[i].x, &b[i].y);
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= n; ++j)
//            for (int k = 1; k <= n; ++k)
//                for (int l = 1; l <= n; ++l)
//                    chk[i][j][k][l] = Cut(a[i], b[j], a[k], b[l]);
//    Recur(1);
    printf("Yes");
    return 0;
}