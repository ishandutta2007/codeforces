#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int T,n,m,k;
int last[Maxn],pre[Maxn],other[Maxn],cnt=0,d[Maxn];
int sz;
set<pair<int,int> >s;
unordered_map<long long,bool> mp;
bool vis[Maxn];
int que[Maxn],tot;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
bool check(int u,int v)
{
    if (mp.find(1LL*n*u+v)!=mp.end()) return true;
    if (mp.find(1LL*n*v+u)!=mp.end()) return true;
    return false;
}
void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        last[i]=0,d[i]=0,vis[i]=false;
    mp.clear();
    s.clear();
    cnt=0;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        mp[1LL*n*u+v]=true;
        mp[1LL*n*v+u]=true;
        insert(u,v),insert(v,u);
        ++d[u],++d[v];
    }
    for (int i=1;i<=n;i++)
        s.insert(make_pair(d[i],i));
    sz=n;
    if ((1LL*k*(k-1))/2>m)
    {
        printf("%d\n",-1);
        return;
    }
    while (sz>0&&(*s.begin()).first<=k-1)
    {
        if ((*s.begin()).first<k-1)
        {
            int u=(*s.begin()).second;
            s.erase(s.begin());
            vis[u]=true;
            --sz;
            for (int q=last[u];q;q=pre[q])
            {
                int v=other[q];
                if (vis[v]) continue;
                --d[u];
                --d[v];
                s.erase(make_pair(d[v]+1,v));
                s.insert(make_pair(d[v],v));
            }
        } else
        {
            int u=(*s.begin()).second;
            tot=1;
            que[1]=u;
            for (int q=last[u];q;q=pre[q])
            {
                int v=other[q];
                if (!vis[v]) que[++tot]=v;
            }
            random_shuffle(que+1,que+tot+1);
            bool flag=true;
            for (int i=1;i<=tot&&flag;i++)
                for (int j=i+1;j<=tot&&flag;j++)
                    if (!check(que[i],que[j]))
                    {
                        flag=false;
                        break;
                    }
            if (flag)
            {
                printf("%d\n",2);
                for (int i=1;i<=tot;i++)
                    printf("%d ",que[i]);
                printf("\n");
                return;
            } else
            {
                vis[u]=true;
                s.erase(s.begin());
                --sz;
                for (int q=last[u];q;q=pre[q])
                {
                    int v=other[q];
                    if (vis[v]) continue;
                    --d[u];
                    --d[v];
                    s.erase(make_pair(d[v]+1,v));
                    s.insert(make_pair(d[v],v));
                }
            }
        }
    }
    if (sz>0)
    {
        printf("%d %d\n",1,sz);
        for (set<pair<int,int> >::iterator it=s.begin();it!=s.end();it++)
            printf("%d ",(*it).second);
        printf("\n");
    } else printf("%d\n",-1);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}