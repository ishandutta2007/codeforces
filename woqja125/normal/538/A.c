#include<stdio.h>
#include<string.h>
char s[200];
char *d="CODEFORCES";
int main()
{
    int n, i, m, j, k;
    scanf("%s", s);
    n = strlen(s);
    m = n-10;
    if(m<0)
    {
        printf("NO");
        return 0;
    }
    for(i=0; i<=n; i++)
    {
        for(k=j=0; j<n; j++)
        {
            if(j>=i && j<i+m) continue;
            if(k>=10 || d[k] != s[j]) break;
            k++;
        }
        if(j==n)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}