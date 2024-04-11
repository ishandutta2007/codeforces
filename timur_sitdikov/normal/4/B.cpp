#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{   
    int n, i, d, min[30], max[30], smin=0, smax=0, dif, tmp;
    scanf("%d %d", &n, &d);
    for(i=0; i<n; i++) 
    {scanf("%d %d", &min[i], &max[i]); smin+=min[i]; smax+=max[i];}
    if (smin>d || smax<d) {printf("NO"); return 0;}
    printf("YES\n");
    dif=d-smin;
    for(i=0; i<n; i++)
    {
        if (smax-max[i]>=d-min[i]) {printf("%d ", min[i]); smin-=min[i]; smax-=max[i]; d-=min[i]; continue;}
        if (smax==d) {printf("%d ", max[i]); smin-=min[i]; smax-=max[i]; d-=max[i]; continue;}
        tmp=smax-d;
        printf("%d ", max[i]-tmp); smax-=max[i]; d=smax; smin-=min[i];
    }
}