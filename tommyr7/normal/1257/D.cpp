#include <bits/stdc++.h>
#define inf 100000007
#define Maxn 200007
using namespace std;
int T,n,m;
int a[Maxn];
int b[Maxn],bin[Maxn];
int st[Maxn][20],nxt[Maxn][20];
int query_max(int lx,int rx)
{
    int t=bin[rx-lx+1];
    return max(st[lx][t],st[rx-(1<<t)+1][t]);
}
bool check(int lx,int len)
{
    int t=query_max(lx,lx+len-1);
    return b[len]>=t;
}
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int mx=0;
    for (int i=1;i<=n;i++)
        mx=max(mx,a[i]);
    scanf("%d",&m);
    for (int i=1;i<=n+5;i++)
        b[i]=0;
    while (m--)
    {
        int p,s;
        scanf("%d%d",&p,&s);
        b[s]=max(b[s],p);
    }
    for (int i=n;i;i--)
        b[i]=max(b[i+1],b[i]);
    if (b[1]<mx)
    {
        printf("%d\n",-1);
        return;
    }
    for (int i=1;i<=n;i++)
        st[i][0]=a[i];
    for (int j=1;j<20;j++)
        for (int i=1;i<=n;i++)
        {
            st[i][j]=st[i][j-1];
            if (i+(1<<(j-1))<=n) st[i][j]=max(st[i][j],st[i+(1<<(j-1))][j-1]);
        }
    for (int i=1;i<=n;i++)
    {
        int lx=1,rx=n-i+1;
        while (rx-lx>1)
        {
            int mid=(lx+rx)/2;
            if (check(i,mid)) lx=mid; else rx=mid;
        }
        if (check(i,rx)) nxt[i][0]=i+rx; else nxt[i][0]=i+lx;
    }
    for (int j=0;j<20;j++)
        nxt[n+1][j]=n+1;
    for (int j=1;j<20;j++)
        for (int i=1;i<=n;i++)
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
    int ans=0;
    int pos=1;
    for (int j=19;j>=0;j--)
        if (nxt[pos][j]<=n) 
        {
            ans+=(1<<j);
            pos=nxt[pos][j];
        }
    ++ans;
    printf("%d\n",ans);
}
int main()
{
    bin[1]=0;
    for (int i=2;i<=200000;i++)
        bin[i]=bin[i/2]+1;
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}