#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e6 + 1000;
int n;
int a[N];
int ans;

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        a[i + 1] += a[i] >> 1;
        ans += a[i] & 1;
    }
    printf("%d\n", ans);

    return 0;
}