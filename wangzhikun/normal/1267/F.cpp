#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int tg[2][100005],n,m,i,hd1,hd2,ka,kb,u,v,a[100005],b[100005],vis[200005];
set<int>st[2];
set<int>::iterator it,it2;
const int inf=1e9;
int main()
{
    scanf("%d%d%d%d",&n,&m,&ka,&kb);
    if(ka>=m||kb>=n)
    {
        printf("No\n");
        return 0;
    }
    for(i=1;i<=ka;i++)scanf("%d",&a[i]);
    for(i=1;i<=kb;i++)scanf("%d",&b[i]);
    for(i=ka+1;i<=m-1;i++)a[i]=a[ka];
    for(i=kb+1;i<=n-1;i++)b[i]=b[kb];
    for(i=m-1;i>0;i--)
    {
        if(vis[a[i]]==0)
        {
            vis[a[i]]=1;
            tg[0][i]=1;
        }
    }
    for(i=n-1;i>0;i--)
    {
        if(vis[b[i]]==0)
        {
            vis[b[i]]=1;
            tg[1][i]=1;
        }
    }
    for(i=1;i<=n+m;i++)
    {
        if(vis[i]==0)
        {
            if(i<=n)st[0].insert(i);
            else st[1].insert(i);
        }
    }
    printf("Yes\n");
    st[0].insert(inf);st[1].insert(inf);
    hd1=hd2=1;
    for(i=1;i<=n+m-2;i++)
    {
        u=*st[0].begin();v=*st[1].begin();
        if(u<v)
        {
            printf("%d %d\n",u,b[hd2++]);
            st[0].erase(u);
            if(tg[1][hd2-1])st[1].insert(b[hd2-1]);           
        }
        else
        {
            printf("%d %d\n",v,a[hd1++]);
            st[1].erase(v);
            if(tg[0][hd1-1])st[0].insert(a[hd1-1]);
        }
    }
    printf("%d %d\n",*st[0].begin(),*st[1].begin());
    return 0;
}