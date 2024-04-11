#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if((a[i]&1)!=(a[1]&1))flag=1;
	}
	if(flag)sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}