#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", (n - 1 + k - 1) / k * 2 - ((n - 1) % k == 1));
    for(int i = 2; i < 2 + k; i++)
        printf("%d %d\n", 1, i);
    for(int i = 2 + k; i <= n; i++)
        printf("%d %d\n", i - k, i);
}