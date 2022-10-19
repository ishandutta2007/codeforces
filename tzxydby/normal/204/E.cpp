#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,ch[N][26],f[N],l[N],sz=1,las,a[N],c,tr[N][26],ts,sd[N],fl[N],dp[N],rt[N],sum[N<<5],lc[N<<5],rc[N<<5];
vector<int>e[N],b[N];
long long ans[N];
char s[N];
void add(int x,int id)
{
	int c=++sz,p=las;
	l[c]=l[p]+1,sd[id]=c,a[c]=id;
	while(p&&!ch[p][x])
	{
		ch[p][x]=c;
		p=f[p];
	}
	if(!p)
		f[c]=1;
	else
	{
		int q=ch[p][x];
		if(l[p]+1==l[q])
			f[c]=q;
		else
		{
			int nq=++sz;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			f[nq]=f[q],l[nq]=l[p]+1;
			while(p&&ch[p][x]==q)
			{
				ch[p][x]=nq;
				p=f[p];
			}
			f[c]=f[q]=nq;
		}
	}
}
void upd(int &k,int l,int r,int x)
{
	if(!k) k=++c;
	if(l==r)
	{
		sum[k]=1;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) upd(lc[k],l,mid,x);
	else upd(rc[k],mid+1,r,x);
	sum[k]=sum[lc[k]]+sum[rc[k]];
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y) return x^y;
	if(l==r)
	{
		sum[x]|=sum[y];
		return x;
	}
	int mid=l+r>>1;
	lc[x]=merge(lc[x],lc[y],l,mid);
	rc[x]=merge(rc[x],rc[y],mid+1,r);
	sum[x]=sum[lc[x]]+sum[rc[x]];
	return x;
}
void dfs(int u)
{
	for(auto i:b[a[u]])
		upd(rt[u],1,n,i);
	for(auto v:e[u])
	{
		dfs(v);
		rt[u]=merge(rt[u],rt[v],1,n);
	}
	fl[u]=(sum[rt[u]]>=k);
}
void dfs2(int u)
{
	if(fl[u])
		dp[u]=l[u];
	for(auto i:b[a[u]])
		ans[i]+=dp[u];
	for(auto v:e[u])
	{
		dp[v]=dp[u];
		dfs2(v);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int m=strlen(s+1),u=0;
		for(int j=1;j<=m;j++)
		{
			int x=s[j]-'a';
			if(!tr[u][x])
				tr[u][x]=++ts;
			u=tr[u][x];
			b[u].push_back(i);
		}
	}
	sd[0]=1;
	for(int i=0;i<=ts;i++)
	{
		for(int x=0;x<26;x++)
		{
			if(!tr[i][x])
				continue;
			las=sd[i];
			add(x,tr[i][x]);
		}
	}
	for(int i=2;i<=sz;i++)
		e[f[i]].push_back(i);
	dfs(1);
	dfs2(1);
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	return 0;
}