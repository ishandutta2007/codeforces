#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],x[200005],y[200005],n1,n2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	x[n1]=y[n2]=-1;
	for(int i=1;i<=n;i++)
	{
		if(x[n1]!=a[i])x[++n1]=a[i];
		else if(y[n2]!=a[i])y[++n2]=a[i];
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	printf("%d\n",n1);
	for(int i=1;i<=n1;i++)printf("%d ",x[i]);
	printf("\n");
	printf("%d\n",n2);
	for(int i=n2;i>=1;i--)printf("%d ",y[i]);
	printf("\n");
	return 0;
}