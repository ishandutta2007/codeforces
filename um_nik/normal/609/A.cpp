#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100100;
int n;
int a[N];
int m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    int k = 0;
    while(m > 0)
        m -= a[k++];
    printf("%d\n", k);

    return 0;
}