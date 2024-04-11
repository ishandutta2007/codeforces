#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[5005];
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		if(m<(i-1)/2)break;
		m-=(i-1)/2;
	}
	if(i>n&&m)
	{
		printf("-1\n");
		return 0;
	}
	a[i]=(a[i-1]+a[i-2]+2)-2*m;
	for(i++;i<=n;i++)a[i]=i*100000+500000000;
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}