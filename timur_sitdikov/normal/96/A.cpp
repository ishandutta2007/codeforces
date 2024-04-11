#include <stdio.h>
#include <string.h>

int main()
{
    int s=0, i, n;
    char c[101], a;
    scanf("%s", &c);
    n=strlen(c);
    for(i=1; i<n; i++)
    {
        if (c[i]==c[i-1]) s++;
        else s=0;
        if (s>=6) {printf("YES"); return 0;}
    }
    printf("NO");
}