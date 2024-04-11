#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int n;
long long h;
int a[Maxn],b[Maxn];
bool check(int x)
{
    long long now=0LL;
    for (int i=1;i<=x;i++)
        a[i]=b[i];
    sort(a+1,a+x+1);
    if (x%2==0)
    {
        for (int i=1;i<=x;i+=2)
            now+=max(a[i],a[i+1]);
        if (now<=h) return true;
        return false;
    } else
    {
        for (int i=1;i<x;i+=2)
            now+=max(a[i],a[i+1]);
        now+=a[x];
        if (now<=h) return true;
        now=0LL;
        for (int i=x;i>1;i-=2)
            now+=max(a[i],a[i-1]);
        now+=a[1];
        if (now<=h) return true;
        return false;
    }
}
int main()
{
    scanf("%d%lld",&n,&h);
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int lx=1,rx=n;
    if (!check(1))
    {
        printf("%d\n",0);
        return 0;
    }
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (check(mid)) lx=mid; else rx=mid;
    }
    if (check(rx)) printf("%d\n",rx); else printf("%d\n",lx);
    return 0;
}