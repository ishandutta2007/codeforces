#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[400];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < 310; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > 0)
            {
                printf("P");
                a[i]--;
            }
            printf("R");
        }
        if (a[n - 1] > 0)
        {
            printf("P");
            a[n - 1]--;
        }
        for (int i = 0; i < n - 1; i++)
            printf("L");
    }
    return 0;
}