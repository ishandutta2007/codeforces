#include <stdio.h>

int is_letter(char c)
{return (c>='A' && c<='Z')||(c>='a' && c<='z');}

int main()
{
    char kl[31][30], c;
    int n, m, i, j, k1, k2, dis[130], ex[130], f, fl[130], x, len, tmp, res;
    scanf("%d %d %d", &n, &m, &x);
    for(i=0; i<n; i++)
        scanf("%s", &kl[i]);
    for(i=0; i<130; i++) {dis[i]=40000; fl[i]=0; }
    for(i=0; i<130; i++) ex[i]=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (kl[i][j]!='S') ex[kl[i][j]]=1;
    f=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (kl[i][j]=='S') {f=1; break;}
    if (f)
    {
        for(i='a'; i<='z'; i++) ex[i-'a'+'A']=ex[i];
    }
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if (kl[i][j]!='S')
            {
                for(k1=0; k1<n; k1++)
                    for(k2=0; k2<m; k2++)
                    {
                        if (kl[k1][k2]=='S')
                        {
                            tmp=(k1-i)*(k1-i)+(k2-j)*(k2-j);
                            if (tmp<dis[kl[i][j]]) dis[kl[i][j]]=tmp;
                        }
                    }
            }
        }
    for(i='a'; i<='z'; i++)
        if (dis[i]<=x*x) fl[i]=1;
    scanf("%d", &len);
    for(; c=getchar(), !is_letter(c); );
    res=0;
    for(i=0; i<len; i++, c=getchar())
    {
        if (!ex[c]) 
        {printf("-1"); return 0;}
        if (c<='Z' &&  !fl[c-'A'+'a']) res++;
    }
    printf("%d", res);
}