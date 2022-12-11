#include <bits/stdc++.h>
using namespace std;
#define Maxn 1007
int n,m;
char s[Maxn];
int cnt[1007][5];
int a[Maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for (int j=1;j<=m;j++)
            ++cnt[j][s[j]-'A'];
    }
    for (int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    long long ans=0LL;
    for (int i=1;i<=m;i++)
    {
        int tmp=0;
        for (int j=0;j<5;j++)
            tmp=max(tmp,cnt[i][j]);
        ans+=1LL*tmp*a[i];
    }
    printf("%lld\n",ans);
    return 0;
}