#include <iostream>
using namespace std;

int n, m, k;
int a[100100][2];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int x = 1;
    int y = 1;
    int idx = 0;
    while (x <= n)
    {
        a[idx][0] = x;
        a[idx][1] = y;
        idx++;
        if (x % 2 == 1)
            y++;
        else
            y--;
        if (y > m)
        {
            x++;
            y = m;
        }
        if (y < 1)
        {
            x++;
            y = 1;
        }
    }
    int p = m * n - 2 * k + 2;
    printf("%d ", p);
    for (int i = 0; i < p; i++)
        printf("%d %d ", a[i][0], a[i][1]);
    printf("\n");
    while (p < n * m)
    {
        printf("2 %d %d %d %d\n", a[p][0], a[p][1], a[p + 1][0], a[p + 1][1]);
        p += 2;
    }
    return 0;
}