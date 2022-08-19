#include <iostream>
#include <cstdlib>
#include <cstdlib>
using namespace std;

int a[20];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        x--;
        a[x]++;
    }
    int res = 0;
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            res += a[i] * a[j];
    printf("%d\n", res);

    return 0;
}