#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
int a[N];
int b[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int x = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        b[i] = max(0, x - a[i]);
        x = max(x, a[i] + 1);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}