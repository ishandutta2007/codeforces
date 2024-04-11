#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

char v[100];

int main()
{   

    int n, m, i, j, ans=0;
    char c[105][105], s[2];
    scanf("%d %d %s", &n, &m, &s);
    for(i=0; i<n; i++) scanf("%s", &c[i]);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (c[i][j]==s[0])
            {
                if (i>0) v[c[i-1][j]]=1;
                if (j>0) v[c[i][j-1]]=1;
                if (i<n) v[c[i+1][j]]=1;
                if (j<m) v[c[i][j+1]]=1;
            }
    for(i='A'; i<='Z'; i++)
        if (v[i] && i!=s[0]) ans++;
    printf("%d", ans);
}