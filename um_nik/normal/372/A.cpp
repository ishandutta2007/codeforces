#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1000100];
int k, l, r;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    l = 0;
    r = n / 2;
    while (l < r)
    {
        k = (l + r + 1) / 2;
        bool ans = true;
        for (int i = 0; i < k; i++)
        {
            if (2 * a[i] > a[n - k + i])
                ans = false;
        }
        if (ans)
        {
            l = k;
        }
        else
        {
            r = k - 1;
        }
    }
    printf("%d\n", n - l);
    //cin >> n;
    return 0;
}