#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = min(a[i], a[i - 1] + 1);
    for (int i = n; i > 0; i--)
        a[i] = min(a[i], a[i + 1] + 1);
    int x = 0;
    for (int i = 1; i <= n; i++)
        x = max(x, a[i]);
    printf("%d\n", x);

    return 0;
}