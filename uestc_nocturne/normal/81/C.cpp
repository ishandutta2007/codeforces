#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node
{
	int va,id;
}q[100100];
bool cmp1(Node x,Node y)
{
	if(x.va==y.va)return x.id>y.id;
	return x.va<y.va;
}
bool cmp2(Node x,Node y)
{
	if(x.va==y.va)return x.id<y.id;
	return x.va<y.va;
}
int in[1000100],n,a,b,i,l,m;
int main()
{
	while(~scanf("%d",&n))
	{
		scanf("%d%d",&a,&b);
		for(i=0;i<n;i++)
		{
			scanf("%d",&q[i].va);
			q[i].id=i;
		}
		if(a<b)
		{
			sort(q,q+n,cmp1);
			for(i=0;i<b;i++)in[q[i].id]=2;
			for(i=b;i<n;i++)in[q[i].id]=1;
		}
		else if(a==b)
		{
			for(i=0;i<a;i++)in[i]=1;
			for(i=a;i<n;i++)in[i]=2;
		}
		else
		{
			sort(q,q+n,cmp2);
			for(i=0;i<a;i++)in[q[i].id]=1;
			for(i=a;i<n;i++)in[q[i].id]=2;
		}
		for(i=0;i<n-1;i++)printf("%d ",in[i]);
		printf("%d\n",in[n-1]);
	}
}