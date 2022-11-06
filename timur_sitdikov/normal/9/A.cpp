#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   

    int a, b, p, q;
    scanf("%d %d", &a, &b);
    if (a<b) a=b;
    if (a==6) {p=1; q=6;}
    if (a==5) {p=1; q=3;}
    if (a==4) {p=1; q=2;}
    if (a==3) {p=2; q=3;}
    if (a==2) {p=5; q=6;}
    if (a==1) {p=1; q=1;}
    printf("%d/%d", p, q);

}