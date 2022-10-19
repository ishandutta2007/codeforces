#include<bits/stdc++.h>
using namespace std;
const int N=150005;
int n,m,k,tim,bg[N],ed[N],fa[N][18],dep[N],s[N],t[N],ls[N];
vector<int>e[N],d[N],p[N],g[N],ss[N];
long long ans;
void dfs(int u,int f)
{
	fa[u][0]=f,bg[u]=++tim,dep[u]=dep[f]+1;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
	ed[u]=tim;
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=17;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=17;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int jp(int u,int k)
{
	for(int i=17;i>=0;i--)
		if(k>>i&1)
			u=fa[u][i];
	return u;
}
bool cmp(int x,int y){return bg[s[x]]<bg[s[y]];}
bool cmp2(int x,int y){return bg[x]<bg[y];}
struct seg1
{
	int tr[N<<2],tag[N<<2],c[N<<2];
	void pd(int k)
	{
		if(c[k])
		{
			tr[k<<1]=0;
			tag[k<<1]=0;
			c[k<<1]=1;
			tr[k<<1|1]=0;
			tag[k<<1|1]=0;
			c[k<<1|1]=1;
			c[k]=0;
		}
		if(tag[k])
		{
			tr[k<<1]+=tag[k];
			tag[k<<1]+=tag[k];
			tr[k<<1|1]+=tag[k];
			tag[k<<1|1]+=tag[k];
			tag[k]=0;
		}
	}
	void add(int k,int l,int r,int a,int b,int v)
	{
		if(l==a&&r==b)
		{
			tr[k]+=v;
			tag[k]+=v;
			return;
		}
		pd(k);
		int mid=l+r>>1;
		if(b<=mid) add(k<<1,l,mid,a,b,v);
		else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
		else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}	
	int ask(int k,int l,int r,int x)
	{
		if(l==r)
			return tr[k];
		pd(k);
		int mid=l+r>>1;
		if(x<=mid) return ask(k<<1,l,mid,x);
		else return ask(k<<1|1,mid+1,r,x);
	}
	void cls()
	{
		c[1]=1;
		tr[1]=tag[1]=0;
	}
}s1,s3;
struct seg2
{
	int tr[N<<6],lc[N<<6],rc[N<<6],c;
	void cls(){c=0;}
	int newnode()
	{
		c++;
		tr[c]=lc[c]=rc[c]=0;
		return c;
	}
	void add(int &k,int l,int r,int x,int v)
	{
		if(!k) k=newnode();
		if(l==r)
		{
			tr[k]+=v;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) add(lc[k],l,mid,x,v);
		else add(rc[k],mid+1,r,x,v);
		tr[k]=tr[lc[k]]+tr[rc[k]];
	}
	int merge(int u,int v,int l,int r)
	{
		if(!u||!v)
			return u^v;
		if(l==r)
		{
			tr[u]+=tr[v];
			return u;
		}
		int mid=l+r>>1;
		lc[u]=merge(lc[u],lc[v],l,mid);
		rc[u]=merge(rc[u],rc[v],mid+1,r);
		tr[u]=tr[lc[u]]+tr[rc[u]];
		return u;
	}
	int query(int k,int l,int r,int a,int b)
	{
		if(!k) return 0;
		if(l==a&&r==b)
			return tr[k];
		int mid=l+r>>1;
		if(b<=mid) return query(lc[k],l,mid,a,b);
		else if(a>mid) return query(rc[k],mid+1,r,a,b);
		else return query(lc[k],l,mid,a,mid)+query(rc[k],mid+1,r,mid+1,b);
	}
}s2;
int st[N],tp,rt[N];
vector<int>v,ps;
void ins(int x)
{
	if(x==1)
		return;
	int l=lca(st[tp],x);
	ps.push_back(l);
	if(l==st[tp])
	{
		st[++tp]=x;
		return;
	}
	while(tp>1&&bg[st[tp-1]]>=bg[l])
	{
		g[st[tp-1]].push_back(st[tp]);
		tp--;
	}
	if(l!=st[tp])
	{
		g[l].push_back(st[tp]);
		st[tp]=l;
	}
	st[++tp]=x;
}
void mg(int u,int v)
{
	if(ss[u].size()<ss[v].size())
		swap(ss[u],ss[v]),swap(rt[u],rt[v]);
	for(auto i:ss[v])
	{
		int r=k-dep[u]+dep[ls[i]];
		if(r<=0)
			ans+=s2.query(rt[u],1,n,1,n);
		else if(dep[t[i]]-dep[ls[i]]>=r)
		{
			int x=jp(t[i],dep[t[i]]-dep[ls[i]]-r);
			ans+=s2.query(rt[u],1,n,bg[x],ed[x]);
		}
		ss[u].push_back(i);
	}
	rt[u]=s2.merge(rt[u],rt[v],1,n);
}
void dfs(int u)
{
	for(auto v:g[u])
	{
		dfs(v);
		mg(u,v);
	}
}
void sol(int x)
{
	ps.clear(),v.clear();
	for(auto i:p[x])
		v.push_back(s[i]),v.push_back(t[i]);
	sort(v.begin(),v.end(),cmp2);
	v.erase(unique(v.begin(),v.end()),v.end());
	st[tp=1]=1;
	for(auto i:v)
		ps.push_back(i);
	for(auto i:v)
		ins(i);
	while(tp>0)
	{
		g[st[tp-1]].push_back(st[tp]);
		tp--;
	}
	s2.cls();
	sort(ps.begin(),ps.end(),cmp2);
	ps.erase(unique(ps.begin(),ps.end()),ps.end());
	for(auto i:ps)
		rt[i]=0,ss[i].clear();
	for(auto i:p[x])
	{
		int r=k-dep[s[i]]+dep[ls[i]];
		if(r<=0)
			ans+=s2.query(rt[s[i]],1,n,1,n);
		else if(dep[t[i]]-dep[ls[i]]>=r)
		{
			int y=jp(t[i],dep[t[i]]-dep[ls[i]]-r);
			ans+=s2.query(rt[s[i]],1,n,bg[y],ed[y]);
		}
		s2.add(rt[s[i]],1,n,bg[t[i]],1);
		ss[s[i]].push_back(i);
	}
	dfs(1);
	for(auto i:ps)
		g[i].clear();
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&s[i],&t[i]);
		if(bg[s[i]]>bg[t[i]])
			swap(s[i],t[i]);
		ls[i]=lca(s[i],t[i]);
		p[ls[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
		d[dep[lca(s[i],t[i])]].push_back(i);
	for(int x=n;x>=1;x--)
	{
		for(auto i:d[x])
			ans+=s1.ask(1,1,n,bg[s[i]])+s1.ask(1,1,n,bg[t[i]]);
		for(auto i:d[x])
		{
			if(dep[s[i]]-dep[ls[i]]>=k)
			{
				int u=jp(s[i],dep[s[i]]-dep[ls[i]]-k);
				s1.add(1,1,n,bg[u],ed[u],1);
			}
			if(dep[t[i]]-dep[ls[i]]>=k)
			{
				int u=jp(t[i],dep[t[i]]-dep[ls[i]]-k);
				s1.add(1,1,n,bg[u],ed[u],1);
			}
		}
	}
	for(int x=1;x<=n;x++)
	{
		sort(p[x].begin(),p[x].end(),cmp);
		s3.cls();
		for(auto i:p[x])
		{
			ans+=s3.ask(1,1,n,bg[s[i]]);
			if(dep[t[i]]-dep[ls[i]]>=k)
			{
				int u=jp(t[i],dep[t[i]]-dep[ls[i]]-k);
				s3.add(1,1,n,bg[u],ed[u],1);
			}
		}
	}
	for(int x=1;x<=n;x++)
		sol(x);
	printf("%lld\n",ans);
	return 0;
}