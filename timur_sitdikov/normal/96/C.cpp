#include <stdio.h>
#include <string.h>

void copy(char *c, char *c1, int l)
{
    int i;
    for(i=0; i<l; i++)
        if (c[i]<='Z') c1[i]=c[i]-'A'+'a';
        else c1[i]=c[i];
    c1[l]=0;
}

int cmp(char *c1, char *c2, int l)
{
    int i;
    for(i=0; i<l; i++)
        if (c1[i]!=c2[i]) return 1;
    return 0;
}

int main()
{
    char c[101], c1[101], ss[100][101], ss1[100][101], a[2], f[101], b, tmp[101];
    int l, len[100], n, i ,j, k, k1;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &ss[i]);
        len[i]=strlen(ss[i]);
        copy(ss[i], ss1[i], len[i]);
    }
    scanf("%s %s", &c, &a);
    if (a[0]<='Z') a[0]+='z'-'Z';
    l=strlen(c);
    copy(c, c1, l);
    for(i=0; i<l; i++) f[i]=0;
    for(i=0; i<l; i++)
    {
        for(j=i; j<l; j++)
            for(k=0; k<n; k++)
                if (len[k]==j-i+1)
                {
                    for(k1=0; k1<len[k]; k1++)
                        tmp[k1]=c1[i+k1];
                    if (!cmp(tmp, ss1[k], len[k])) 
                    {for(k1=i; k1<=j; k1++) f[k1]=1;}
                }
    }
    for(i=0; i<l; i++)
        if (f[i])
        {
            if (c1[i]!=a[0]) c1[i]=a[0];
            else if (c1[i]=='a') c1[i]='b';
            else c1[i]='a';
        }
    for(i=0; i<l; i++)
        if (c[i]<='Z') c1[i]-='z'-'Z';
    c1[l]=0;
    printf("%s", c1);
}