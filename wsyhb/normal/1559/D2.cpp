#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int fa[2][max_n];
int get_fa(int k,int x)
{
	return fa[k][x]!=x?fa[k][x]=get_fa(k,fa[k][x]):x;
}
inline void merge(int k,int x,int y)
{
	x=get_fa(k,x),y=get_fa(k,y);
	assert(x!=y);
	fa[k][x]=y;
}
int p1[2],p2[2];
typedef pair<int,int> P;
vector<P> ans;
inline void merge(int x,int y)
{
	for(int k=0;k<=1;++k)
	{
		int rx=get_fa(k,x),ry=get_fa(k,y);
		assert(rx!=ry);
		fa[k][rx]=ry;
	}
	ans.push_back(P(x,y));
}
int main()
{
	int n,m[2];
	scanf("%d%d%d",&n,&m[0],&m[1]);
	for(int k=0;k<=1;++k)
	{
		for(int i=1;i<=n;++i)
			fa[k][i]=i;
		for(int i=1;i<=m[k];++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			merge(k,u,v);
		}
		p1[k]=1,p2[k]=2;
	}
	while(p2[0]<=n&&p2[1]<=n)
	{
		for(int k=0;k<=1;++k)
		{
			while(p2[k]<=n&&get_fa(k,p1[k])==get_fa(k,p2[k]))
				p1[k]=p2[k]++;
		}
		if(p2[0]<=n&&p2[1]<=n)
		{
			int x=p1[0],y=p2[0],u=p1[1],v=p2[1];
			if(get_fa(1,x)!=get_fa(1,y))
				merge(x,y);
			else
			{
				if(get_fa(1,x)==get_fa(1,u))
					swap(u,v);
				assert(get_fa(1,x)!=get_fa(1,u));
				if(get_fa(0,x)!=get_fa(0,u))
					merge(x,u);
				else
				{
					assert(get_fa(0,y)!=get_fa(0,u));
					merge(y,u);
				}
			}
		}
	}
	int h=(int)ans.size();
	assert(h==n-1-max(m[0],m[1]));
	printf("%d\n",h);
	for(vector<P>::iterator it=ans.begin();it!=ans.end();++it)
		printf("%d %d\n",it->first,it->second);
	return 0;
}