#include <bits/stdc++.h>
using namespace std;

int w[1000005];
int z[2000005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d",&t);
        while (z[t])
        {
            z[t] = 0;
            t++;
        }
        z[t] = 1;
    }
    printf("%d\n", accumulate(z, z + 2000000, 0));
}