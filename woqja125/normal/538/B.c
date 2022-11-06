#include<stdio.h>
int out[10];
int main()
{
    int n, p = 1, i, j, mt=0;
    scanf("%d",&n);
    for(i=1; n!=0; i++)
    {
        int t = n%10;
        if(t > mt) mt = t;
        for(j=1; j<=t; j++) out[j] += p;
        p*=10;
        n/=10;
    }
    printf("%d\n", mt);
    for(i=1; i<=mt; i++) printf("%d ", out[i]);
    return 0;
}