#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int k=31;k>=0;k--)
	{
		int ans=2147483647;
		int num=0;
		for(int i=1;i<=n;i++)
		  if((1<<k)&a[i])
		    ans&=a[i],num++;
		if(ans%(1<<k)==0)
		{
			printf("%d\n",num);
			for(int i=1;i<=n;i++)
			  if((1<<k)&a[i])
			    printf("%d ",a[i]);
			printf("\n");
			return 0;
		}
	}
	return 0;
}