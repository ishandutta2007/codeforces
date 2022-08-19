#include <iostream>
using namespace std;

int n, d;
int sum;

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x + 10;
    }
    sum -= 10;
    if (sum > d)
    {
        printf("-1\n");
        return 0;
    }
    d -= sum;
    d /= 5;
    printf("%d\n", 2 * n - 2 + d);

    return 0;
}