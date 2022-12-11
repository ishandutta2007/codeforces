#include <bits/stdc++.h>
#define Maxn 100007
int n,q;
int cnt,a[Maxn];
int main()
{
    scanf("%d%d",&n,&q);
    cnt=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==1) ++cnt;
    }
    while (q--)
    {
        int op,pos;
        scanf("%d%d",&op,&pos);
        if (op==1)
        {
            a[pos]=1-a[pos];
            if (a[pos]==1) ++cnt; else --cnt;
        }
        else
        {
            if (pos<=cnt) printf("%d\n",1); else printf("%d\n",0);
        }
    }
    return 0;
}