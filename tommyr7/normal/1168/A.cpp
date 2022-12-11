#include <bits/stdc++.h>
using namespace std;
#define Maxn 600007
int n,m;
int a[Maxn];
bool check(int x)
{
    int now=0;
    if (a[1]+x>=m) now=0; else now=a[1];
    for (int i=2;i<=n;i++)
    {
        if (a[i]+x<m)
        {
            if (a[i]+x<now) return false;
            if (now<a[i]) now=a[i];
        }
        else if (a[i]+x>=m)
        {
            if (now>(a[i]+x)%m&&now<a[i]) now=a[i];
        }
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int lx=0,rx=m-1;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (check(mid)) rx=mid; else lx=mid;
    }
    if (check(lx)) printf("%d\n",lx); else printf("%d\n",rx);
    return 0;
}