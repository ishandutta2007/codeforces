#include<bits/stdc++.h>
using namespace std;
const int N=400005,inf=1000000001;
int n,m,a[N],f[N],l[N],fa[N][20],las=1,sz=1,p[N],ed[N],ans[N],b[N];
map<int,int>ch[N];
vector<int>e[N];
struct nd{int d,x,c;};
vector<nd>q[N];
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]+=v;
}
int ask(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b[i];
	return v;
}
void ins(int c)
{
	int p=las,x=++sz;
	l[x]=l[p]+1;
	while(p&&ch[p].find(c)==ch[p].end())
	{
		ch[p][c]=x;
		p=f[p];
	}
	if(!p)
		f[x]=1;
	else
	{
		int q=ch[p][c];
		if(l[p]+1==l[q])
			f[x]=q;
		else
		{
			int nq=++sz;
			ch[nq]=ch[q];
			f[nq]=f[q];
			l[nq]=l[p]+1;
			while(p&&ch[p][c]==q)
			{
				ch[p][c]=nq;
				p=f[p];
			}
			f[q]=f[x]=nq;
		}
	}
	las=x;
}
void dfs(int u)
{
	for(auto [d,x,c]:q[u])
		ans[d]-=c*ask(x);
	if(p[u])
		add(p[u],1);
	for(auto v:e[u])
		dfs(v);
	for(auto [d,x,c]:q[u])
		ans[d]+=c*ask(x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		a[i]=a[i+1]-a[i];
	a[n]=inf;
	for(int i=n+1;i<n+n;i++)
		a[i]=-a[i-n];
	n=n*2-1;
	for(int i=1;i<=n;i++)
	{
		ins(a[i]);
		ed[i]=las;
		if(i<=n/2)
			p[las]=i;
	}
	for(int i=1;i<=sz;i++)
	{
		e[f[i]].push_back(i);
		fa[i][0]=f[i];
	}
	for(int j=1;j<=18;j++)
		for(int i=1;i<=sz;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int pl,pr;
		scanf("%d%d",&pl,&pr);
		if(pl==pr)
		{
			ans[i]=n/2;
			continue;
		}
		pr--;
		int vl=pl+(n+1)/2,vr=pr+(n+1)/2;
		int u=ed[vr],len=pr-pl+1;
		for(int i=18;i>=0;i--)
			if(l[fa[u][i]]>=len)
				u=fa[u][i];
		q[u].push_back({i,(n+1)/2,1});
		q[u].push_back({i,min(pr+len,(n+1)/2),-1});
		q[u].push_back({i,max(0,pl-2),1});
	}
	dfs(1);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}