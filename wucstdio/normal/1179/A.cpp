#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,q,a[500005],head,tail,b[500005],x[500005],y[500005],maxx;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	head=1,tail=n;
	while(a[head]!=maxx)
	{
		int v1=a[head];
		int v2=a[head+1];
		x[++m]=v1;
		y[m]=v2;
		if(v1<v2)swap(v1,v2);
		a[++head]=v1;
		a[++tail]=v2;
	}
	for(int i=head+1;i<=tail;i++)b[i-head]=a[i];
	while(q--)
	{
		long long v;
		scanf("%I64d",&v);
		if(v<=m)printf("%d %d\n",x[v],y[v]);
		else
		{
			v-=m;
			printf("%d ",maxx);
			printf("%d\n",b[(v-1)%(n-1)+1]);
		}
	}
	return 0;
}