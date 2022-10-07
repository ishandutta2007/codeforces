#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll ans;
struct Set
{
	int pa[200005],size[200005];
	void pre()
	{
		for(int i=1;i<=n;i++)
		  pa[i]=i,size[i]=1;
	}
	int find(int x)
	{
		return pa[x]==x?x:pa[x]=find(pa[x]);
	}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x!=y)pa[x]=y,size[y]+=size[x];
	}
	void calc()
	{
		for(int i=1;i<=n;i++)
		  if(find(i)==i)
		    ans+=1ll*size[i]*(size[i]-1);
	}
}A,B;
int num[200005];
int main()
{
	scanf("%d",&n);
	A.pre(),B.pre();
	for(int i=1;i<n;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		if(l==0)A.merge(u,v);
		else B.merge(u,v);
	}
	A.calc();
	B.calc();
	for(int i=1;i<=n;i++)
	  ans+=1ll*(B.size[B.find(i)]-1)*(A.size[A.find(i)]-1);
	printf("%I64d\n",ans);
	return 0;
}