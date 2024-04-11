#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 111;
int a[N];
int b[N];
int n, m;

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        int mm = -1;
        int v = -1;
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            if (x > mm)
            {
                mm = x;
                v = j;
            }
        }
        a[v]++;
    }
    int mm = -1;
    int v = -1;
    for (int i = 0; i < m; i++)
        if (a[i] > mm)
        {
            mm = a[i];
            v = i;
        }
    printf("%d\n", v + 1);

    return 0;
}