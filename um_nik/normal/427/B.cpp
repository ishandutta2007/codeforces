#include <iostream>
using namespace std;

int n;
int m;
int t;
int a[200100];
int ans;
int sz = 0;

int main()
{
    scanf("%d%d%d", &n, &t, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] <= t)
            a[i] = 1;
        else
            a[i] = 0;
    }
    for (int i = 0; i <= n + 1; i++)
    {
        if (a[i] == 0)
        {
            ans += max(0, sz - m + 1);
            sz = 0;
        }
        else
            sz++;
    }
    printf("%d\n", ans);
//  cin >> n;

    return 0;
}