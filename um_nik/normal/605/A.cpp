#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100100;
int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        a[x] = i;
    }
    int ans = 0;
    int l = 0;
    while(l < n)
    {
        int r = l + 1;
        while(r < n && a[r] > a[r - 1]) r++;
        ans = max(ans, r - l);
        l = r;
    }
    printf("%d\n", n - ans);

    return 0;
}