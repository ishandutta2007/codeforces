#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

const int N = 555 * 555;
int n;
int a[N];
int b[N];
int m;
map<int, int> w;

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x % y));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n * n);
    reverse(a, a + n * n);
    m = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (w[a[i]] > 0)
        {
            w[a[i]]--;
            continue;
        }
        b[m++] = a[i];
        for (int j = 0; j < m - 1; j++)
            w[gcd(a[i], b[j])] += 2;
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}