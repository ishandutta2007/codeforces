#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define maxn 600005
using namespace std;
int q,n=300000;
struct Edg
{
	int x,y;
}a[maxn],b[maxn];
int c[maxn],last[maxn];
struct Option
{
	int l,r,x,y;
}opt[maxn];
bool operator < (Edg A,Edg B)
{
	if(A.x==B.x)return A.y<B.y;
	return A.x<B.x;
}
bool operator == (Edg A,Edg B)
{
	return (A.x==B.x&&A.y==B.y);
}
int fa[maxn],sz1[maxn],sz2[maxn],size[maxn];
int find(int x)
{
	while(fa[x]!=x)x=fa[x];
	return x;
}
vector<pii> ve[maxn<<2];
void add(int rt,int l,int r,int ql,int qr,pii x)
{
	if(ql<=l&&r<=qr)
	{
		ve[rt].push_back(x);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)add(rt<<1,l,mid,ql,qr,x);
	if(qr>mid)add(rt<<1|1,mid+1,r,ql,qr,x);
}
int s1[maxn],s2[maxn],top;
ll Ans[maxn],res=0;
void dfs(int rt,int l,int r)
{
    if(l>r)return;
    int bot=top;
    for(int i=0;i<ve[rt].size();++i)
    {
        int u=ve[rt][i].first,v=ve[rt][i].second;
        if(find(u)==find(v))continue;
        u=find(u),v=find(v);
        if(size[u]<size[v])swap(u,v);
        res-=1ll*sz1[u]*sz2[u]+1ll*sz1[v]*sz2[v];
        fa[v]=u;
		size[u]+=size[v];sz1[u]+=sz1[v],sz2[u]+=sz2[v];
		s1[++top]=v;s2[top]=u;
        res+=1ll*sz1[u]*sz2[u];
    }
    if(l==r)
    {
    	Ans[l]=res;
    }
    int mid=(l+r)>>1;
    if(l!=r)
	{
		dfs(rt<<1,l,mid);
		dfs(rt<<1|1,mid+1,r);
	}
    while(top>bot)
    {
        int u=s1[top],v=s2[top];
        res-=1ll*sz1[v]*sz2[v];
        fa[u]=u;
		size[v]-=size[u];sz1[v]-=sz1[u];sz2[v]-=sz2[u];
		res+=1ll*sz1[u]*sz2[u]+1ll*sz1[v]*sz2[v];
		top--;
    }
}
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].y+=n;
		b[i]=a[i];
	}
	sort(a+1,a+q+1);
	int d=unique(a+1,a+q+1)-a-1;
	for(int i=1;i<=q;++i)c[i]=lower_bound(a+1,a+d+1,b[i])-a;
	int cnt=0;
	for(int i=1;i<=q;++i)
	{
		if(!last[c[i]])last[c[i]]=i;
		else
		{
			++cnt;
			opt[cnt].l=last[c[i]],opt[cnt].r=i-1,opt[cnt].x=a[c[i]].x,opt[cnt].y=a[c[i]].y;
			last[c[i]]=0;
		}
	}
	for(int i=1;i<=d;++i)if(last[i])
	{
		++cnt;
		opt[cnt].l=last[i],opt[cnt].r=q,opt[cnt].x=a[i].x,opt[cnt].y=a[i].y;
		last[i]=0;
	}
	for(int i=1;i<=cnt;++i)add(1,1,q,opt[i].l,opt[i].r,mp(opt[i].x,opt[i].y));
	for(int i=1;i<=n;++i)fa[i]=i,sz1[i]=1,size[i]=1;
	for(int i=1;i<=n;++i)fa[i+n]=i+n,sz2[i+n]=1,size[i+n]=1;
	dfs(1,1,q);
	for(int i=1;i<=q;++i)printf("%I64d ",Ans[i]);
	return 0;
}