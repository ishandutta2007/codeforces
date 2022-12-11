#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);

    sort(a, a + n);

    int minv = INT_MAX, minc = 0;

    for (int i = 1; i < n; i++)
    {
        int dif = a[i] - a[i-1];
        if (dif < minv) minv = dif, minc = 0;
        if (dif == minv) ++minc;
    }
    printf("%d %d\n", minv, minc);
}