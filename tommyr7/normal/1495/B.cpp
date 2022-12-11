#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int n,p[Maxn];
int f[Maxn],mx1[Maxn],mx2[Maxn];
int dp(int id)
{
    if (f[id]!=0) return f[id];
    f[id]=1;
    if (id>1&&p[id-1]>p[id]) f[id]=max(f[id],dp(id-1)+1);
    if (id<n&&p[id+1]>p[id]) f[id]=max(f[id],dp(id+1)+1);
    return f[id];
}
bool check(int id)
{
    int lx=id-1,rx=id+1;
    while (lx>1&&p[lx-1]<p[lx]) --lx;
    while (rx<n&&p[rx+1]<p[rx]) ++rx;
    int llx=lx,rrx=rx;
    while (llx>1&&p[llx-1]>p[llx]) --llx;
    while (rrx<n&&p[rrx+1]>p[rrx]) ++rrx;
    if (max(mx1[lx-1],mx2[rx+1])>=max(id-lx+1,rx-id+1)) return false;
    if (max(lx-llx+1,id-lx+1)>=rx-id+1)
    {
        if ((id-lx)%2==1) return false;
        if (lx-llx+1>=id-lx+1) return false;
    }
    if (max(rrx-rx+1,rx-id+1)>=id-lx+1)
    {
        if ((rx-id)%2==1) return false;
        if (rrx-rx+1>=rx-id+1) return false;
    }
    for (int i=lx+1;i<rx;i++)
        if (i!=id)
        {
            if (abs(i-id)%2==1)
            {
                if (i<id)
                {
                    if (id-i+1>=rx-id+1) return false;
                } else
                {
                    if (i-id+1>=id-lx+1) return false;
                }
            }
        }
    return true;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        if (f[i]==0) f[i]=dp(i);
    for (int i=1;i<=n;i++)
        mx1[i]=max(mx1[i-1],f[i]);
    for (int i=n;i;i--)
        mx2[i]=max(mx2[i+1],f[i]);
    int ans=0;
    for (int i=2;i<n;i++)
        if (p[i]>p[i-1]&&p[i]>p[i+1])
        {
            if (check(i)) ++ans;
        }
    printf("%d\n",ans);
    return 0;
}