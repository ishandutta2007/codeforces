#include <bits/stdc++.h>
#define Maxn 600007
using namespace std;
int n,m;
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int ans[Maxn];
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        insert(a,b);
        insert(b,a);
    }
    ans[1]=1;
    for (int q=last[1];q;q=pre[q])
    {
        int v=other[q];
        ans[v]=-1;
    }
    for (int i=2;i<=n;i++)
        if (ans[i]!=-1) ans[i]=1;
    int r=0;
    for (int i=1;i<=n;i++)
        if (ans[i]==-1) r=i;
    if (r==0)
    {
        printf("%d\n",-1);
        return 0;
    }
    ans[r]=2;
    for (int q=last[r];q;q=pre[q])
    {
        int v=other[q];
        if (ans[v]!=1) ans[v]=3;
    }
    for (int i=1;i<=n;i++)
        if (ans[i]!=1&&ans[i]!=3&&ans[i]!=2) ans[i]=2;
    int cnt1=0,cnt2=0,cnt3=0;
    for (int i=1;i<=n;i++)
        if (ans[i]==1) ++cnt1; else if (ans[i]==2) ++cnt2; else ++cnt3;
    bool flag=true;
    for (int i=1;i<=n;i++)
    {
        int tmp1=0,tmp2=0,tmp3=0;
        for (int q=last[i];q;q=pre[q])
        {
            int v=other[q];
            if (ans[v]==ans[i]) flag=false;
            else if (ans[v]==1) ++tmp1;
            else if (ans[v]==2) ++tmp2;
            else ++tmp3;
        }
        if (tmp1!=cnt1&&ans[i]!=1) flag=false;
        if (tmp2!=cnt2&&ans[i]!=2) flag=false;
        if (tmp3!=cnt3&&ans[i]!=3) flag=false;
    }
    if (cnt1==0) flag=false;
    if (cnt2==0) flag=false;
    if (cnt3==0) flag=false;
    if (!flag) printf("%d\n",-1);
    else 
    {
        for (int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}