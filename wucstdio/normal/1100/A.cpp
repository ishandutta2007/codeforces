#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,a[105],ans,num1,num2;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
	{
		num1=num2=0;
		for(int j=1;j<=n;j++)
		{
			if((j-i)%k==0)continue;
			if(a[j]==1)num1++;
			else num2++;
		}
		ans=max(ans,abs(num1-num2));
	}
	printf("%d\n",ans);
	return 0;
}