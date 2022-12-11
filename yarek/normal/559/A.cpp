#include <bits/stdc++.h>
using namespace std;

int f(int k)
{
    return k * k;
}

int main()
{
    int a[6];
    for(int i = 0; i < 6; i++)
        scanf("%d", a + i);
    printf("%d\n", f(a[0] + a[1] + a[2]) - f(a[0]) - f(a[2]) - f(a[4]));
}