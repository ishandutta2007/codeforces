#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[1000005],top;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		top=0;
		for(int i=1;i*i<=n;i++)
		{
			a[++top]=i;
			if(n/i!=i)a[++top]=n/i;
		}
		sort(a+1,a+top+1);
		printf("%d\n",top+1);
		for(int i=0;i<=top;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}