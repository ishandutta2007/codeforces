#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
#define Maxm 8000057
#define modp 998244353
int n,m;
int a[Maxn],b[Maxn],bin[1000007];
int last[Maxm],pre[Maxm],other[Maxm],cnt=0;
pair<int,int> len[Maxm];
bool vis[Maxm];
pair<int,int> dis[Maxm];
int calc(int id,int t)
{
    return t*n+id;
}
void insert(int u,int v,pair<int,int> l)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
    len[cnt]=l;
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if (a.first<=20&&b.first>20) return true;
    if (a.first>20&&b.first<=20) return false;
    if (a.first>20&&b.first>20)
    {
        if (a.first!=b.first) return a.first<b.first;
        return a.second<b.second;
    }
    int tmp1=a.second+bin[a.first];
    int tmp2=b.second+bin[b.first];
    return tmp1<tmp2;
}
priority_queue<pair<pair<int,int>,int> >pq;
int main()
{
    bin[0]=1;
    for (int i=1;i<=1000000;i++)
        bin[i]=(2LL*bin[i-1])%modp;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d",&a[i],&b[i]);
    for (int k=0;k<20;k++)
        for (int i=1;i<=m;i++)
            if (k%2==0) insert(calc(a[i],k),calc(b[i],k),make_pair(0,1));
            else insert(calc(b[i],k),calc(a[i],k),make_pair(0,1));
    for (int k=0;k<19;k++)
        for (int i=1;i<=n;i++)
            insert(calc(i,k),calc(i,k+1),make_pair(1,0));
    for (int i=1;i<=n;i++)
        insert(calc(i,19),calc(i,18),make_pair(1,0));
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=n*20;i++)
        dis[i]=make_pair(1000000,1000000);
    dis[1]=make_pair(0,0);
    pq.push(make_pair(make_pair(0,0),1));
    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int q=last[u];q;q=pre[q])
        {
            int v=other[q];
            if (make_pair(dis[u].first+len[q].first,dis[u].second+len[q].second)<dis[v])
            {
                dis[v]=make_pair(dis[u].first+len[q].first,dis[u].second+len[q].second);
                pq.push(make_pair(make_pair(-dis[v].first,-dis[v].second),v));
            }
        }
    }
    pair<int,int> ans=make_pair(1000000,1000000);
    for (int i=1;i<=20;i++)
        if (cmp(dis[i*n],ans)) ans=dis[i*n];
    int anss=(bin[ans.first]+ans.second)%modp;
    anss=(anss+modp-1)%modp;
    anss=(anss%modp+modp)%modp;
    printf("%d\n",anss);
    return 0;
}