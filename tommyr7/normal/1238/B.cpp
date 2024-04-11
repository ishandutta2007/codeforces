#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int T,n,r;
int pos[Maxn];
bool check(int k)
{
    int cnt=0,tmp=0;
    for (int i=1;i<=n;i++)
        if (pos[i]>1LL*k*r)
        {
            if (pos[i]!=tmp)
            {
                ++cnt;
                tmp=pos[i];
            }
        }
    return (cnt<=k);
}
void solve()
{
    scanf("%d%d",&n,&r);
    for (int i=1;i<=n;i++)
        scanf("%d",&pos[i]);
    sort(pos+1,pos+n+1);
    int lx=1,rx=n;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (check(mid)) rx=mid; else lx=mid;
    }
    if (check(lx)) printf("%d\n",lx); else printf("%d\n",rx);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}