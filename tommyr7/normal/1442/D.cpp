#include <bits/stdc++.h>
using namespace std;
#define Maxn 3007
int n,k;
int a[Maxn];
vector<long long> s[Maxn],tmp;
long long ans=0LL;
void solve(int lx,int rx,vector<long long> g)
{
    vector<long long> f;
    if (lx<rx)
    {
        int mid=(lx+rx)/2;
        for (int i=0;i<=k;i++)
            f.push_back(g[i]);
        for (int i=mid+1;i<=rx;i++)
            for (int j=k;j>=a[i];j--)
                f[j]=max(f[j],f[j-a[i]]+s[i][a[i]]);
        solve(lx,mid,f);
        f.clear();
        for (int i=0;i<=k;i++)
            f.push_back(g[i]);
        for (int i=lx;i<=mid;i++)
            for (int j=k;j>=a[i];j--)
                f[j]=max(f[j],f[j-a[i]]+s[i][a[i]]);
        solve(mid+1,rx,f);
    } else
    {
        for (int i=0;i<=a[lx]&&i<=k;i++)
            ans=max(ans,s[lx][i]+g[k-i]);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        long long sum=0LL;
        s[i].push_back(sum);
        for (int j=1;j<=a[i];j++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
            s[i].push_back(sum);
        }
    }
    for (int i=0;i<=k;i++)
        tmp.push_back(0LL);
    solve(1,n,tmp);
    printf("%lld\n",ans);
    return 0;
}