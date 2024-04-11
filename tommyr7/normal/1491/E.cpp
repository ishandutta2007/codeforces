#include <bits/stdc++.h>
using namespace std;
#define Maxn 400007
int n;
int last[Maxn],pre[Maxn],other[Maxn],cnt=1;
bool flag[Maxn];
int sz[Maxn];
int f[30];
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
    flag[cnt]=true;
}
void dfs(int u,int fa,int k,int &tmp,int &tmp1,int &tmp2)
{
    sz[u]=1;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa&&flag[q])
        {
            dfs(v,u,k,tmp,tmp1,tmp2);
            if (sz[v]==f[k-1]||sz[v]==f[k-2]) tmp=q,tmp1=v,tmp2=u;
            sz[u]+=sz[v];
        }
    }
}
bool check(int rt,int k)
{
    if (k<=3) return true;
    int tmp=-1,tmp1=-1,tmp2=-1;
    dfs(rt,-1,k,tmp,tmp1,tmp2);
    if (tmp!=-1)
    {
        if (sz[tmp1]>sz[rt]-sz[tmp1]) swap(tmp1,tmp2);
        flag[tmp]=false;
        flag[tmp^1]=false;
        return check(tmp1,k-2)&&check(tmp2,k-1);
    }
    else return false;
}
int main()
{
    f[0]=1;
    f[1]=1;
    for (int i=2;i<=30;i++)
        f[i]=f[i-1]+f[i-2];
    scanf("%d",&n);
    if (n<=2)
    {
        printf("YES\n");
        return 0;
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v);
        insert(v,u);
    }
    int k=-1;
    for (int i=0;i<30;i++)
        if (f[i]==n) k=i;
    if (k==-1) printf("NO\n");
    else if (check(1,k)) printf("YES\n"); 
    else printf("NO\n");
    return 0;
}