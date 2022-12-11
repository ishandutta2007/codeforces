#include <bits/stdc++.h>
using namespace std;
#define Maxn 300007
int n;
int a[Maxn],b[Maxn],ans[Maxn];
bool cmp1(int x,int y)
{
    return a[x]<a[y];
}
bool cmp2(int x,int y)
{
    return a[x]>a[y];
}
int main()
{
    scanf("%d",&n);
    int cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        if (a[i]>b[i]) ++cnt1; else ++cnt2;
    }
    int now=0;
    if (cnt1>cnt2)
    {
        printf("%d\n",cnt1);
        for (int i=1;i<=n;i++)
            if (a[i]>b[i]) ans[++now]=i;
        sort(ans+1,ans+now+1,cmp1);
        for (int i=1;i<=now;i++)
            printf("%d ",ans[i]);
        printf("\n");
    } else
    {
        printf("%d\n",cnt2);
        for (int i=1;i<=n;i++)
            if (a[i]<b[i]) ans[++now]=i;
        sort(ans+1,ans+now+1,cmp2);
        for (int i=1;i<=now;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}