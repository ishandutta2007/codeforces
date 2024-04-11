#include <iostream>
using namespace std;

int n, k, m;
int a[100100];

int main()
{
    scanf("%d%d", &n, &k);
    if (n == 1)
    {
        if (k == 0)
            printf("1\n");
        else
            printf("-1\n");
        return 0;
    }
    if (k < n / 2)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 2; i < n; i++)
        a[i] = i - 1;
    k -= (n - 2) / 2;
    m = k;
    while (m < n)
        m *= 2;
    a[0] = m;
    a[1] = m + k;
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
//  cin >> n;
    return 0;
}