#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   

    int m[100005], t1, t2, i, j, n;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &m[i]);
    for(t1=t2=i=0, j=n-1; i<=j;)
    {
        if (t1<=t2) {t1+=m[i]; i++;}
        else {t2+=m[j]; j--;}
    }
    printf("%d %d", i, n-i);
}