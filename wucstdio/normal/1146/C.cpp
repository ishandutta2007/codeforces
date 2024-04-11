#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,ans,a[1005],b[1005],num1,num2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int x=0;x<=9;x++)
		{
			num1=num2=0;
			for(int j=1;j<=n;j++)
			{
				if((1<<x)&j)a[++num1]=j;
				else b[++num2]=j;
			}
			if(num1==0||num2==0)continue;
			printf("%d %d ",num1,num2);
			for(int i=1;i<=num1;i++)
			  printf("%d ",a[i]);
			for(int i=1;i<=num2;i++)
			  printf("%d ",b[i]);
			printf("\n");
			fflush(stdout);
			int v;
			scanf("%d",&v);
			ans=max(ans,v);
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
	return 0;
}