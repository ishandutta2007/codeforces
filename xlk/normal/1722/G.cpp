#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++)
    {
        scanf("%d", &n);
        int z = 0;
        for (int i = 0; i < n - 3; i++)
        {
            printf("%d ", i);
            z ^= i;
        }
        int x = 1 << 20, y = 1 << 21;
        printf("%d %d %d\n", z ^ x ^ y, x, y);
    }
    return 0;
}