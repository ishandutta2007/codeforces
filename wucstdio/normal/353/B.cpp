#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1005],b[2005],c[1005],num,num1,num2,now;
bool flag[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&b[i]);
		a[b[i]]++;
	}
	for(int i=10;i<100;i++)
	{
		if(a[i]>1)num1++,num2++;
		else if(a[i]==1)num++;
	}
	num1+=num/2,num2+=num-num/2;
	printf("%d\n",num1*num2);
	now=1;
	for(int i=10;i<100;i++)
	{
		if(a[i]<=1)continue;
		if(a[i]&1)c[i]=a[i]/2+(now=1-now);
		else c[i]=a[i]/2;
	}
	now=2;
	for(int i=1;i<=2*n;i++)
	{
		if(a[b[i]]==1)printf("%d ",now=3-now);
		else if(!flag[b[i]])
		{
			printf("1 ");
			c[b[i]]--;
			if(c[b[i]]==0)flag[b[i]]=1;
		}
		else printf("2 ");
	}
	printf("\n");
	return 0;
}