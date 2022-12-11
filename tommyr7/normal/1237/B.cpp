#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int pos[Maxn],a[Maxn],n,ans=0;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
    int tmp=0;
    for (int i=1;i<=n;i++)
    {
        if (pos[a[i]]<tmp) ++ans;
        tmp=max(tmp,pos[a[i]]);
    }
    printf("%d\n",ans);
    return 0;
}