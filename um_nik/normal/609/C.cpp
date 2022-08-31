#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100100;
int n;
int a[N];
int x;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        x += a[i];
    int p = x / n;
    int q = x % n;
    q = n - q;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += max(0, a[i] - (p + (i >= q ? 1 : 0)));
    printf("%d\n", res);

    return 0;
}