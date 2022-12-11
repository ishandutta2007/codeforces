#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i <= n; i += a)
        if((n - i) % b == 0)
        {
            for(int j = 0; j < i; j += a)
            {
                for(int k = 1; k < a; k++)
                    printf("%d ", j + k + 1);
                printf("%d ", j + 1);
            }
            for(int j = i; j < n; j += b)
            {
                for(int k = 1; k < b; k++)
                    printf("%d ", j + k + 1);
                printf("%d ", j + 1);
            }
            puts("");
            return 0;
        }
    puts("-1");
}