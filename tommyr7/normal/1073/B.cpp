#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,a[Maxn],b[Maxn],pos[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int now=0;
    for (int i=1;i<=n;i++)
    {
        if (pos[b[i]]<=now) printf("%d ",0); else
        {
            printf("%d ",pos[b[i]]-now);
            now=pos[b[i]];
        }
    }
    printf("\n");
    return 0;
}