#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
#define T 357
char s[Maxn];
int a[Maxn],pre[Maxn],pos[Maxn];
int que[Maxn];
int n,m=0;
long long ans=0LL;
int calc(int n,int a,int b)
{
    return max(0,(n-T*b-a)/b);
}
int calc(int lx,int rx,int a,int b)
{
    return calc(rx,a,b)-calc(lx-1,a,b);
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
    {
        a[i]=s[i]-'0';
        if (a[i]==1) pos[++m]=i;
        pre[i]=pre[i-1]+a[i];
    }
    pos[m+1]=n+1;
    for (int k=1;k<=T&&k<=n;k++)
    {
        for (int i=0;i<=n;i++)
            que[i]=i-k*pre[i];
        sort(que,que+n+1);
        int now=1;
        for (int i=1;i<=n;i++)
        {
            if (que[i]==que[i-1])
            {
                ans+=now;
                ++now;
            } else now=1;
        }
    }
    for (int i=1;i<=n/T;i++)
    {
        for (int l=0;l<n;l++)
            if (pre[l]+i<=m) ans+=calc(pos[pre[l]+i],pos[pre[l]+i+1]-1,l,i);
    }
    printf("%lld\n",ans);
    return 0;
}