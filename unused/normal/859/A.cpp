#include <bits/stdc++.h>
using namespace std;

int r[100];

int main()
{
    int k;
    scanf("%d",&k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d",&r[i]);
    }

    printf("%d\n", max(0, *max_element(r + 1, r + 1 + k) - 25));
}