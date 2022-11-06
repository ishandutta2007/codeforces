#include<stdio.h>
int main()
{
    int n, m = 0, t;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &t);
        if(t>m)m=t;
    }
    printf("%d", m);
    return 0;
}