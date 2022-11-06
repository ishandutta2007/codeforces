#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{   
    long long n, x, y, i;
    scanf("%I64d %I64d %I64d", &n, &x, &y);
    if (n<=y && n-1+(y-n+1)*(y-n+1)>=x)
    {
        printf("%lld\n", y-n+1);
        for(i=1; i<n; i++) printf("1\n");
    }
    else printf("-1");
}