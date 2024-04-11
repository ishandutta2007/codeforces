#include <iostream>
using namespace std;

int n;
int ans;
int a[1000100];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        ans ^= x;
    }
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] ^ i;
    for (int i = 2; i <= n; i++)
    {
        int x = n / i;
        if (x % 2 == 1)
            ans ^= a[i - 1];
        x = n % i;
        ans ^= a[x];
    }
    printf("%d\n", ans);
//  cin >> n;
    return 0;
}