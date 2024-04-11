#include<cstdio>
using namespace std;
int n,a[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2==0)a[i]--;
	}
	for(int i=1;i<=n;i++)
	  printf("%d ",a[i]);
	return 0;
}