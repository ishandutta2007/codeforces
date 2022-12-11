#include <bits/stdc++.h>
using namespace std;

int dat[20];
int f(int x, int y)
{
    if (is_sorted(dat + x, dat + y)) return y - x;
    return max(f(x, (x + y) / 2), f((x + y) / 2, y));
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    printf("%d\n", f(0, n));
}