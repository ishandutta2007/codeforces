#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int T,n;
long long s;
int a[Maxn],b[Maxn];
int c[Maxn];
bool check(int x)
{
    long long nows=s;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        nows-=a[i];
        if (b[i]>=x) c[++cnt]=max(0,x-a[i]);
    }
    if (cnt<(n+1)/2) return false;
    sort(c+1,c+cnt+1);
    long long tmp=0LL;
    for (int i=1;i<=(n+1)/2;i++)
        tmp+=c[i];
    return (nows>=tmp);
}
void solve()
{
    scanf("%d%lld",&n,&s);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    int lx=1,rx=1000000000;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (check(mid)) lx=mid; else rx=mid;
    }
    if (check(rx)) printf("%d\n",rx); else printf("%d\n",lx);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}