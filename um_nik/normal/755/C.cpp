#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int IT = 10;
const int N = (int)1e4 + 100;
int n;
int a[N];
int b[N];

int main()
{
    //freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        int x = i;
        for (int j = 0; j < IT; j++)
            x = a[x];
        b[i] = min(x, a[x]);
    }
    sort(b, b + n);
    printf("%d\n", unique(b, b + n) - b);
    fflush(stdout);

    return 0;
}