#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],pre[100005],suf[100005],res;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	pre[0]=suf[n+1]=2147483647;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]&(~a[i]);
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]&(~a[i]);
	res=1;
	for(int i=1;i<=n;i++)
	{
		if((pre[i-1]&suf[i+1]&a[i])>(pre[res-1]&suf[res+1]&a[res]))
		  res=i;
	}
	printf("%d ",a[res]);
	for(int i=1;i<res;i++)printf("%d ",a[i]);
	for(int i=res+1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}