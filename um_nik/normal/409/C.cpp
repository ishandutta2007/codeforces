#include <iostream>
using namespace std;

int a[6];
int ans = 1000;

int main()
{
    for (int i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    ans = min(ans, a[0] / 1);
    ans = min(ans, a[1] / 1);
    ans = min(ans, a[2] / 2);
    ans = min(ans, a[3] / 7);
    ans = min(ans, a[4] / 4);
    printf("%d\n", ans);

    return 0;
}