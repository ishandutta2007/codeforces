#include<bits/stdc++.h>
using namespace std;
const int N=2005;
struct UnionFind
{
	int parent[N],rnk[N];
	UnionFind(int n)
	{
		for(int i=0;i<=n;i++)
		{
			parent[i]=i;
			rnk[i]=1;
		}
	}
	int root(int x)
	{
		if(parent[x]!=x)
			parent[x]=root(parent[x]);
		return parent[x];
	}
	void connect(int x,int y)
	{
		int rx=root(x),ry=root(y);
		if(rx==ry)
			return;
		if(rx>ry)
		{
			parent[ry]=rx;
			rnk[rx]+=rnk[ry];	
		} 
		if(rx<=ry)
		{
			parent[rx]=ry;
			rnk[ry]+=rnk[rx];
		}
	}
};
int a[N],b[N];
int main()
{
	int n;
	scanf("%d",&n);
	UnionFind uf(2000); 
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]=b[y]=1;
		uf.connect(x,y+1000);
	}
	int ans=-1;
	for(int i=1;i<=1000;i++)
		ans+=a[i]+b[i];
	for(int i=1;i<=2000;i++)
		if(uf.root(i)!=i)
			ans--;
	printf("%d\n",ans); 
	return 0;
}