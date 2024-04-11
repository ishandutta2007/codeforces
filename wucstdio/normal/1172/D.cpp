#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[1005],b[1005],pa[1005],pb[1005],fromx[1005],fromy[1005],tox[1005],toy[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		pb[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pa[a[i]]=i;
	}
	for(int i=n;i>1;i--)
	{
		if(a[i]==i&&b[i]==i)continue;
		fromx[++m]=i;
		fromy[m]=a[i];
		a[pa[i]]=a[i];
		pa[a[i]]=pa[i];
		tox[m]=b[i];
		toy[m]=i;
		b[pb[i]]=b[i];
		pb[b[i]]=pb[i];
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++)printf("%d %d %d %d\n",fromx[i],fromy[i],tox[i],toy[i]);
	return 0;
}