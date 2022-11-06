#include <stdio.h>

int gcd(int a, int b)
{return b? gcd(b, a%b): a;}

int abs(int a)
{return (a<0? -a: a);}

int main()
{
    int a, b, g;
    scanf("%d %d", &a, &b);
    g=gcd(a, b);
    a/=g; b/=g;
    if (abs(a-b)==1) {printf("Equal"); return 0;}
    if (a>b) printf("Masha");
    else printf("Dasha");
}