#include <iostream>
using namespace std;

int n, k;
bool a[1000100];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x] = 1;
        if (a[1000001 - x])
            k++;
    }
    printf("%d\n", n);
    for (int i = 1; i <= 1000000; i++)
    {
        if (k > 0 && !a[i] && !a[1000001 - i])
        {
            k--;
            printf("%d %d ", i, 1000001 - i);
        }
        if (a[i] && !a[1000001 - i])
            printf("%d ", 1000001 - i);
    }
    printf("\n");
//  cin >> n;
    return 0;
}