#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
int a[N];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        y = max(a[i] - a[0], a[n - 1] - a[i]);
        if (i == 0)
            x = a[1] - a[0];
        else if (i == n - 1)
            x = a[n - 1] - a[n - 2];
        else
            x = min(a[i] - a[i - 1], a[i + 1] - a[i]);
        printf("%d %d\n", x, y);
    }

    return 0;
}