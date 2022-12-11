#include <bits/stdc++.h>
using namespace std;
#define Maxn 300007
char s[Maxn];
int r[Maxn];
int n;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
    {
        r[i]=n+1;
        for (int j=1;i+2*j<=n&&j<=300;j++)
            if (s[i]==s[i+j]&&s[i]==s[i+2*j]) r[i]=min(r[i],i+2*j);
    }
    for (int i=n-1;i;i--)
        r[i]=min(r[i],r[i+1]);
    long long ans=0LL;
    for (int i=1;i<=n;i++)
        ans+=n+1-r[i];
    printf("%lld\n",ans);
    return 0;
}