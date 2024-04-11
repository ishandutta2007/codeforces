#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n--;
		int k=n;
		while(k&(k-1))k=k&(k-1);
		for(int i=k-1;i>=0;i--)printf("%d ",i);
		for(int i=k;i<=n;i++)printf("%d ",i);
		printf("\n");
	}
	return 0;
}