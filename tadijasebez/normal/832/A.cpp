#include <stdio.h>
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    if((a/b)%2==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}