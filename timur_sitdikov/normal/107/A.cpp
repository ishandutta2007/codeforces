#include <stdio.h>

int in[1005], out[1005], mout[1005], n, min;

int main()
{
    int i, m, a, b, c, j, stack[2000][3], top=0;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        in[b]=a; out[a]=b; mout[a]=c;
    }
    for(i=1; i<=n; i++)
        if (out[i] && !in[i])
        {
            min=mout[i];
            for(j=i; mout[j]; j=out[j])
                if (mout[j]<min) min=mout[j];
            stack[top][0]=i; stack[top][1]=j; stack[top][2]=min; top++;
        }
    printf("%d\n", top);
    for(i=0; i<top; i++)
        printf("%d %d %d\n", stack[i][0], stack[i][1], stack[i][2]); 
}