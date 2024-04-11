#include <stdio.h>
#include <cstring>
int main()
{
    int n,i,len;
    char s[1000];
    scanf("%i",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&s);
        len=(unsigned) strlen(s);
        if(len>10)
        printf("%c%i%c\n",s[0],len-2,s[len-1]);
        else printf("%s\n",s);
    }
    return 0;
}