#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
vector<ii>a[100020];
vector<int>p;
map<int,vector<pair<ii,int>>>b;
long long z[100020];
int f[100020],c[100020];
int n;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	c[F(x)]+=c[F(y)];
	f[F(y)]=F(x);
}
int dfs(int x,int y,int w)
{
	p.push_back(w);
	z[w]=c[x];
	for(auto i:a[x])
		if(i.X!=y)
			z[w]+=dfs(i.X,x,i.Y);
	a[x].clear();
	return z[w];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		c[f[i]=i]=1;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		b[z].push_back(make_pair(ii(x,y),i));
	}
	for(auto&c:b)
	{
		set<int>s;
		for(auto&i:c.Y)
		{
			int x=F(i.X.X),y=F(i.X.Y);
			s.insert(x);
			a[x].push_back(ii(y,i.Y));
			a[y].push_back(ii(x,i.Y));
		}
		for(auto i:s)
			if(a[i].size())
			{
				long long u=dfs(i,0,0);
				for(auto j:p)
					z[j]*=(u-z[j])*2;
				p.clear();
			}
		for(auto&i:c.Y)
			U(i.X.X,i.X.Y);
	}
	long long u=*max_element(z+1,z+n);
	printf("%I64d %d\n",u,count(z+1,z+n,u));
	for(int i=1;i<n;i++)
		if(z[i]==u)
			printf("%d ",i);
}