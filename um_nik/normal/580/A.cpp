#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
int a[N];
int ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int len = 0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        if (last <= a[i])
        {
            len++;
            last = a[i];
        }
        else
        {
            len = 1;
            last = a[i];
        }
        ans = max(ans, len);
    }
    printf("%d\n", ans);

    return 0;
}