#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int n,m,k;
int a[Maxn];
bool flag[Maxn];
pair<int,int> s[Maxn];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=make_pair(a[i],i);
    }
    sort(s+1,s+n+1);
    for (int i=1;i<n+1-i;i++)
        swap(s[i],s[n+1-i]);
    long long ans=0LL;
    for (int i=1;i<=m*k;i++)
    {
        ans+=s[i].first;
        flag[s[i].second]=true;
    }
    printf("%lld\n",ans);
    int cnt=0,now=0;
    for (int i=1;i<=n;i++)
    {
        if (flag[i]) ++cnt;
        if (cnt==m)
        {
            cnt=0;
            ++now;
            if (now<k) printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}