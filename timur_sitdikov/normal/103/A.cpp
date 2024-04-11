#include <stdio.h>

int main()
{
    long long i, n, s, a[101];
    scanf("%I64d", &n);
    for(s=0, i=0; i<n; i++)
    {
        scanf("%I64d", &a[i]);
        s+=(a[i]-1)*(i+1)+1;
    }
    printf("%I64d", s);
}