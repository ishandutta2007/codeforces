#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return *(char*)c1-*(char*)c2;}

int main()
{   
   
    char c1[15], c2[15];
    int l1, l2, i, f1, f2, ind;
    scanf("%s %s", &c1, &c2);
    l1=strlen(c1); l2=strlen(c2);
    if (l2>1 && c2[0]=='0') {printf("WRONG_ANSWER"); return 0;}
    for(i=0; i<l2 && c2[i]=='0'; i++);
    if (i==l2)
    {
        if (l1==1 && c1[0]=='0') printf("OK");
        else printf("WRONG_ANSWER");
        return 0; 
    }
    ind=i;
    for(i=ind; i<l2; i++)
        c2[i-ind]=c2[i];
    c2[i-ind]=0;
    l2=strlen(c2);
    if (l1!=l2) {printf("WRONG_ANSWER"); return 0;}
    if (l1==1)
    {
        if (c1[0]==c2[0]) printf("OK");
        else printf("WRONG_ANSWER");
        return 0;
    }
    qsort(c1, l1, 1, cmp);
    for(i=0; c1[i]=='0'; i++);
    if (i) {c1[0]=c1[i]; c1[i]='0';}
    if (!strcmp(c1, c2)) printf("OK");
    else printf("WRONG_ANSWER");
}