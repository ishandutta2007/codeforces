#include<bits/stdc++.h>
using namespace std;
const int max_V=3e5+5;
const int max_E=18e5+5;
int End[max_E],Last[max_V],Next[max_E],Len[max_E],E;
inline void add_edge(int x,int y,int z)
{
//	fprintf(stderr,"x=%d y=%d z=%d\n",x,y,z);
	End[++E]=y;
	Next[E]=Last[x];
	Last[x]=E;
	Len[E]=z;
}
int n,m,p,q;
inline int id(int x,int y)
{
	return (x-1)*m+y;
}
inline bool check(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}
long long dis[max_V];
int main()
{
	scanf("%d%d%d%d",&n,&m,&p,&q);
	vector<vector<char> > Map(n+2,vector<char>(m+2));
	map<char,bool> ok;
	ok['L']=ok['R']=ok['D']=ok['U']=ok['.']=ok['#']=true;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			char ch=getchar();
			while(!ok.count(ch))
				ch=getchar();
			Map[i][j]=ch;
		}
	int V=n*m;
	for(int i=1;i<=V;++i)
		dis[i]=1e18;
	typedef pair<long long,int> P;
	priority_queue<P,vector<P>,greater<P> > Q;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(Map[i][j]=='L')
			{
				assert(Map[i][j+1]=='R');
				if(check(i-1,j+1))
					add_edge(id(i-1,j+1),id(i,j),p);
				if(check(i+1,j+1))
					add_edge(id(i+1,j+1),id(i,j),p);
				if(check(i,j+2))
					add_edge(id(i,j+2),id(i,j),q);
				if(check(i-1,j))
					add_edge(id(i-1,j),id(i,j+1),p);
				if(check(i+1,j))
					add_edge(id(i+1,j),id(i,j+1),p);
				if(check(i,j-1))
					add_edge(id(i,j-1),id(i,j+1),q);
			}
			else if(Map[i][j]=='U')
			{
				assert(Map[i+1][j]=='D');
				if(check(i+1,j-1))
					add_edge(id(i+1,j-1),id(i,j),p);
				if(check(i+1,j+1))
					add_edge(id(i+1,j+1),id(i,j),p);
				if(check(i+2,j))
					add_edge(id(i+2,j),id(i,j),q);
				if(check(i,j-1))
					add_edge(id(i,j-1),id(i+1,j),p);
				if(check(i,j+1))
					add_edge(id(i,j+1),id(i+1,j),p);
				if(check(i-1,j))
					add_edge(id(i-1,j),id(i+1,j),q);
			}
			else if(Map[i][j]=='.')
			{
				dis[id(i,j)]=0;
				Q.push(P(0,id(i,j)));
			}
		}
	while(!Q.empty())
	{
		long long d=Q.top().first;
		int x=Q.top().second;
		Q.pop();
		if(dis[x]<d)
			continue;
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(dis[y]>d+Len[i])
			{
				dis[y]=d+Len[i];
				Q.push(P(dis[y],y));
			}
		}
	}
	long long ans=2e18;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
//			fprintf(stderr,"i=%d j=%d d=%lld\n",i,j,dis[id(i,j)]);
			if(i<n)
				ans=min(ans,dis[id(i,j)]+dis[id(i+1,j)]);
			if(j<m)
				ans=min(ans,dis[id(i,j)]+dis[id(i,j+1)]);
		}
	if(ans>=1e18)
		ans=-1;
	printf("%lld\n",ans);
	return 0;
}