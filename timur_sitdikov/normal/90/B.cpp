#include <stdio.h>

int main()
{
    char c[101][101], f[101][101];
    int i, j, k, v[150], h, w;
    scanf("%d %d", &h, &w);
    for(i=0;i<h;i++)
        scanf("%s",&c[i]);
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)f[i][j]=0;
    for(i=0;i<h;i++)
    {
        for(k='a';k<='z';k++) v[k]=0;
        for(j=0;j<w;j++) v[c[i][j]]++;
        for(j=0;j<w;j++)
            if(v[c[i][j]]>1) f[i][j]=1;
    }
    for(j=0;j<w;j++)
    {
        for(k='a';k<='z';k++) v[k]=0;
        for(i=0;i<h;i++) v[c[i][j]]++;
        for(i=0;i<h;i++)
            if(v[c[i][j]]>1) f[i][j]=1;
    }
    for(i=0; i<h;i++)
        for(j=0;j<w;j++)
            if (!f[i][j]) putchar(c[i][j]);
}