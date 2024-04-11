#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n=10000,m,f[N],b[N],d[N],c,t,vis[N],vp[N];
vector<pair<int,int>>e[N];
vector<int>a[2];
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
void dfs(int u,int f,int p)
{
	vp[u]=1;
	for(int &i=b[u];i<e[u].size();i++)
	{
		int v=e[u][i].first,id=e[u][i].second;
		if(vis[id])
			continue;
		vis[id]=1;
		dfs(v,id,p);
	}
	if(f)
		a[p].push_back(f);
}
void ch(vector<int>&a)
{
	vector<int>b;
	int p=-1;
	for(int i=0;i<a.size();i++)
		if(a[i]>m)
			p=i;
	if(p==-1)
		return;
	for(int i=p+1;i<a.size();i++)
		b.push_back(a[i]);
	for(int i=0;i<p;i++)
		b.push_back(a[i]);
	a=b;
}
int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&m);	
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
		d[u]++,d[v]++;
		u=fa(u),v=fa(v);
		if(u!=v)
			f[u]=v;
	}
	for(int i=1;i<=n;i++)
		c+=(d[i]&1),t+=(d[i]&&f[i]==i);
	if(c>4||t>=3)
	{
		puts("-1");
		return 0;
	}
	if(m==1)
	{
		puts("-1");
		return 0;
	}
	if(c==0)
	{
		if(t==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i])
				{
					dfs(i,0,0);
					break;
				}
			}
			printf("%d\n",a[0].size()-1);
			for(int i=0;i<a[0].size()-1;i++)
				printf("%d ",a[0][i]);
			puts("");
			printf("%d\n",1);
			printf("%d\n",a[0].back());
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i])
				{
					dfs(i,0,0);
					break;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(d[i]&&!vp[i])
				{
					dfs(i,0,1);
					break;
				}
			}
			printf("%d\n",a[0].size());
			for(int i=0;i<a[0].size();i++)
				printf("%d ",a[0][i]);
			puts("");
			printf("%d\n",a[1].size());
			for(int i=0;i<a[1].size();i++)
				printf("%d ",a[1][i]);
			puts("");
		}
	}
	if(c==2)
	{
		vector<int>x;
		for(int i=1;i<=n;i++)
			if(d[i]&1)
				x.push_back(i);
		if(t==1)
		{
			e[x[0]].emplace_back(x[1],m+1);
			e[x[1]].emplace_back(x[0],m+1);
			for(int i=1;i<=n;i++)
			{
				if(d[i])
				{
					dfs(i,0,0);
					break;
				}
			}
			ch(a[0]);
			printf("%d\n",a[0].size()-1);
			for(int i=0;i<a[0].size()-1;i++)
				printf("%d ",a[0][i]);
			puts("");
			printf("%d\n",1);
			printf("%d\n",a[0].back());
		}
		else
		{
			e[x[0]].emplace_back(x[1],m+1);
			e[x[1]].emplace_back(x[0],m+1);
			for(int i=1;i<=n;i++)
			{
				if(d[i])
				{
					dfs(i,0,0);
					break;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(d[i]&&!vp[i])
				{
					dfs(i,0,1);
					break;
				}
			}
			ch(a[0]);
			ch(a[1]);
			printf("%d\n",a[0].size());
			for(int i=0;i<a[0].size();i++)
				printf("%d ",a[0][i]);
			puts("");
			printf("%d\n",a[1].size());
			for(int i=0;i<a[1].size();i++)
				printf("%d ",a[1][i]);
			puts("");
		}
	}
	if(c==4)
	{
		vector<int>x;
		for(int i=1;i<=n;i++)
			if(d[i]&1)
				x.push_back(i);
		int fl=1;
		for(int i=1;i<4;i++)
			if(fa(x[i])!=fa(x[0]))
				fl=0;
		if(fl&&t==2)
		{
			puts("-1");
			return 0;
		}
		if(!fl)
		{
			for(int i=1;i<4;i++)
			{
				if(fa(x[i])==fa(x[0]))
				{
					swap(x[i],x[1]);
					break;
				}
			}
			e[x[0]].emplace_back(x[1],m+1);
			e[x[1]].emplace_back(x[0],m+1);
			e[x[2]].emplace_back(x[3],m+2);
			e[x[3]].emplace_back(x[2],m+2);
			for(int i=1;i<=n;i++)
			{
				if(d[i])
				{
					dfs(i,0,0);
					break;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(d[i]&&!vp[i])
				{
					dfs(i,0,1);
					break;
				}
			}
			ch(a[0]);
			ch(a[1]);
			printf("%d\n",a[0].size());
			for(int i=0;i<a[0].size();i++)
				printf("%d ",a[0][i]);
			puts("");
			printf("%d\n",a[1].size());
			for(int i=0;i<a[1].size();i++)
				printf("%d ",a[1][i]);
			puts("");
		}
		else
		{
			e[x[0]].emplace_back(x[1],m+1);
			e[x[1]].emplace_back(x[0],m+1);
			e[x[2]].emplace_back(x[3],m+2);
			e[x[3]].emplace_back(x[2],m+2);
			for(int i=1;i<=n;i++)
			{
				if(d[i])
				{
					dfs(i,0,0);
					break;
				}
			}
			int p1=-1,p2=-1;
			for(int i=0;i<a[0].size();i++)
			{
				if(a[0][i]==m+1)
					p1=i;
				if(a[0][i]==m+2)
					p2=i;
			}
			if(p1>p2)
				swap(p1,p2);
			vector<int>a1,a2;
			for(int i=p2+1;i<a[0].size();i++)
				a1.push_back(a[0][i]);
			for(int i=0;i<p1;i++)
				a1.push_back(a[0][i]);
			for(int i=p1+1;i<p2;i++)
				a2.push_back(a[0][i]);
			printf("%d\n",a1.size());
			for(auto i:a1)
				printf("%d ",i);
			puts("");
			printf("%d\n",a2.size());
			for(auto i:a2)
				printf("%d ",i);
		}
	}
	return 0;
}