#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   

    char m[10];
    int i;
    for(i=0; i<3; i++)
        scanf("%s", &m[3*i]);
    for(i=0; i<9; i++)
        if (m[i]!=m[8-i]) 
        {printf("NO"); return 0;}
    printf("YES");

}