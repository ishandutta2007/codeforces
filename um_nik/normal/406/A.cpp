#include <iostream>
using namespace std;

int n;
int ans;
int q;
int a[1001][1001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        ans ^= a[i][i];
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 3)
        {
            printf("%d", ans);
        }
        else
        {
            scanf("%d", &x);
            ans = ans ^ 1;
        }
    }
    printf("\n");
    return 0;
}