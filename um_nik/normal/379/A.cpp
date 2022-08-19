#include <iostream>
using namespace std;

int a, b, ans;

int main()
{
    scanf("%d%d", &a, &b);
    ans = 0;
    while (a >= b)
    {
        ans += b;
        a -= b - 1;
    }
    ans += a;
    printf("%d\n", ans);
    return 0;
}