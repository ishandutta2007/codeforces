#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   
 
    int i, j, k, n, ans=0, val, pow10[10];
    for(i=1, pow10[0]=1; i<10; i++) pow10[i]=pow10[i-1]*10;
    scanf("%d", &n);
    for(j=1; j<1024; j++)
    {
        for(val=0, k=0; k<10; k++)
        {
            val*=10;
            if (j&(1<<k)) 
                val+=1;
        }
        if (val<=n) 
            ans++;
    }
    printf("%d", ans);
}