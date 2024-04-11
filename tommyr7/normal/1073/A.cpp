#include <bits/stdc++.h>
#define Maxn 2007
using namespace std;
int n;
char s[Maxn];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (s[i]!=s[j])
            {
                printf("YES\n");
                printf("%c%c\n",s[i],s[j]);
                return 0;
            }
    printf("NO\n");
    return 0;
}