#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
#define modp 998244353
int T,n,k;
int a[Maxn],b[Maxn],pos[Maxn],nxt[Maxn],pre[Maxn];
bool flag[Maxn];
void del(int pos)
{
    if (pos==0) return;
    nxt[pre[pos]]=nxt[pos];
    pre[nxt[pos]]=pre[pos];
}
void solve()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=k;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        flag[i]=false,pos[a[i]]=i;
    for (int i=1;i<=k;i++)
        flag[pos[b[i]]]=true;
    for (int i=1;i<=n;i++)
        nxt[i]=i+1,pre[i]=i-1;
    int ans=1;
    for (int i=1;i<=k;i++)
    {
        int t=pos[b[i]];
        int cnt=0,p=0;
        if (pre[t]>0&&!flag[pre[t]]) ++cnt,p=pre[t];
        if (nxt[t]<=n&&!flag[nxt[t]]) ++cnt,p=nxt[t];
        ans=(1LL*ans*cnt)%modp;
        del(p);
        flag[t]=false;
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}