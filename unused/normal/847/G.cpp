#include <bits/stdc++.h>
using namespace std;

int z[7];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int k;
            scanf("%1d",&k);
            z[j] += k;
        }
    }
    printf("%d\n", *max_element(z, z + 7));
}