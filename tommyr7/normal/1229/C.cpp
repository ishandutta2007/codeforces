#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n,m,q;
vector<int> s[Maxn];
int cnt[Maxn][2];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a>b) swap(a,b);
        s[a].push_back(b);
        ++cnt[a][0];
        ++cnt[b][1];
    }
    long long ans=0LL;
    for (int i=1;i<=n;i++)
        ans+=1LL*cnt[i][0]*cnt[i][1];
    printf("%lld\n",ans);
    scanf("%d",&q);
    while (q--)
    {
        int x;
        scanf("%d",&x);
        ans-=1LL*cnt[x][0]*cnt[x][1];
        for (int i=0;i<(int)s[x].size();i++)
        {
            int y=s[x][i];
            --cnt[y][1];
            ans-=cnt[y][0];
            s[y].push_back(x);
            ++cnt[y][0];
            ans+=cnt[y][1];
            ++cnt[x][1];
        }
        cnt[x][0]=0;
        s[x].clear();
        printf("%lld\n",ans);
    }
    return 0;
}