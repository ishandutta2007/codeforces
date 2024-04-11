#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int m1[505][26][26], prv[505][26][26];
char c[505][505];

int main()
{   

    int m, n, i, j, cur, min, mini, minj, stack[1000], top=0;
    char i1, j1, i2, j2;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        scanf("%s", &c[i]);
    if (n==1 && m==1)
    {
        printf("0\n%c\n", c[1][0]); return 0;
    }
    for(i=1; i<=n; i++)
        for(j=0; j<m; j++) c[i][j]-='a';
    for(i=1; i<=n; i++)
        for(i1=0; i1<26; i1++)
            for(j1=0; j1<26; j1++)
                m1[i][i1][j1]=1000000000;
    for(i=1; i<=n; i++)
    {
        for(i1=0; i1<26; i1++)
            for(j1=0; j1<26; j1++)
            {
                if (i1==j1) continue;
                for(cur=j=0; j<m; j+=2)
                    if (c[i][j]!=i1) cur++;
                for(j=1; j<m; j+=2)
                    if (c[i][j]!=j1) cur++;
                min=1000000000;
                for(i2=0; i2<26; i2++)
                {
                    if (i2==i1) continue;
                    for(j2=0; j2<26; j2++)
                    {
                        if (j2==i2 || j2==j1) continue;
                        if (m1[i-1][i2][j2]<min) 
                        {min=m1[i-1][i2][j2]; mini=i2; minj=j2;}
                    }
                }
                m1[i][i1][j1]=min+cur;
                prv[i][i1][j1]=50*mini+minj;
            }
    }
    min=1000000000;
    for(i1=0; i1<26; i1++)
        for(j1=0; j1<26; j1++)
        {
            if (j1==i1) continue;
            if (m1[n][i1][j1]<min) 
            {min=m1[n][i1][j1]; mini=i1; minj=j1;}
        }
    printf("%d\n", min);
    i1=mini; j1=minj;
    for(top=n-1; top>=0; top--)
    {
        stack[top]=50*i1+j1;
        i2=prv[top+1][i1][j1]/50;
        j2=prv[top+1][i1][j1]%50;
        i1=i2; j1=j2;
    }
    top=n;
    for(i=0; i<top; i++)
    {
        for(j=0; j<m; j++)
        {
            if (j&1) putchar(stack[i]%50+'a');
            else putchar(stack[i]/50+'a');
        }
        putchar('\n');
    }
}