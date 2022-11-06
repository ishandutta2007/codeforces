#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{   
    int n;
    scanf("%d", &n);
    if (n>2 && !(n&1)) printf("YES");
    else printf("NO");
}