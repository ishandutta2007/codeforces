#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < k; i++)
    {
        printf("%c", 'a' + i);
    }
    for (int i = 0; i < n - k; i++)
    {
        printf("%c", 'a' + i % 2);
    }
    printf("\n");
}