#include <stdio.h>

int main()
{
    int n,i,m,l,r;
    scanf("%i %i",&n,&m);
    while(m--) scanf("%i %i",&l,&r);
    for(i=1;i<=n;i++) printf("%i",i&1);
    return 0;
}