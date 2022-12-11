#include <bits/stdc++.h>
#define Maxn 1007
using namespace std;
char s[Maxn];
int n;
int ans[Maxn];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    int now='b';
    for (int i=n;i;i--)
    {
        if (s[i]==now) ans[i]=0;
        else
        {
            ans[i]=1;
            now='a'+'b'-now;
        }
    }
    for (int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}