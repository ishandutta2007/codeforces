#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	int num=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i])continue;
		num++;
		for(int j=i;j<=n;j+=i)
		  if(!a[j])a[j]=num;
	}
	for(int i=2;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}