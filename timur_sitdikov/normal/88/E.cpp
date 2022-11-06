#include <stdio.h>
#include <math.h>

int g[100002];
int used[100002];

int main()
{
    int i, j, d=100001, v, sq, a, s, k, n;
    for(i=0; i<d; i++) used[i]=0;
    g[1]=g[2]=0;
    for(v=1, i=3; i<d; i++, v++)
    {
        sq=sqrt((double)(2*i));
        for(j=2; j<=sq; j++)
        {
            a=(2*i-j*j+j)/(2*j);
            if (a*2*j==2*i-j*j+j)
            {
                for(s=0, k=a; k<a+j; k++)
                    s^=g[k];
                used[s]=v;
            }
        }
        for(j=0; used[j]==v; j++);
        g[i]=j;
    }
    scanf("%d", &n);
    if (!g[n]) {printf("-1"); return 0;}
    i=n;
    sq=sqrt((double)(2*i));
    for(j=2; j<=sq; j++)
    {
        a=(2*i-j*j+j)/(2*j);
        if (a*2*j==2*i-j*j+j)
        {
            for(s=0, k=a; k<a+j; k++)
                s^=g[k];
            if (s==0) {printf("%d", j); return 0;}
        }
    }
}