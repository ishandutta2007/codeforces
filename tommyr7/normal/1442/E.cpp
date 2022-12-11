#include <bits/stdc++.h>
using namespace std;
#define Maxn 400007
int T,n;
int col[Maxn],dd[Maxn],d[Maxn];
vector<int> r;
bool flag[Maxn];
int que[Maxn];
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int ans;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void solve(int x)
{
    for (int i=1;i<=n;i++)
        d[i]=dd[i],flag[i]=true;
    int lx=0,rx=0;
    int tmp=0;
    r.clear();
    while (rx<n)
    {
        ++tmp;
        if (tmp<=2)
        {
            for (int i=1;i<=n;i++)
                if (d[i]<=1&&col[i]!=(3-x)&&flag[i]) 
                {
                    flag[i]=false;
                    que[++rx]=i;
                }
        } else
        {
            for (int ii=0;ii<(int)r.size();ii++)
            {
                int i=r[ii];
                flag[i]=false;
                que[++rx]=i;
            }
        }
        r.clear();
        while (lx<rx)
        {
            int u=que[++lx];
            for (int q=last[u];q;q=pre[q])
            {
                int v=other[q];
                if (flag[v])
                {
                    --d[v];
                    if (d[v]<=1&&flag[v])
                    {
                        if (col[v]!=(3-x))
                        {
                            flag[v]=false;
                            que[++rx]=v;
                        } else r.push_back(v);
                    }
                }
            }
        }
        x=3-x;
    }
    ans=min(ans,tmp);
}
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&col[i]);
    cnt=0;
    for (int i=1;i<=n;i++)
        last[i]=0,dd[i]=0;
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
        ++dd[u],++dd[v];
    }
    ans=n;
    solve(1);
    solve(2);
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}