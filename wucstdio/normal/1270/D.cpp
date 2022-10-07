#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,num1,num2,flag=-1;
int main()
{
	scanf("%d%d",&n,&k);
	printf("? ");
	for(int i=1;i<=k;i++)printf("%d ",i);
	printf("\n");
	fflush(stdout);
	int pos,v;
	scanf("%d%d",&pos,&v);
	for(int i=1;i<=k;i++)
	{
		printf("? ");
		for(int j=1;j<=k+1;j++)
		  if(i!=j)printf("%d ",j);
		printf("\n");
		fflush(stdout);
		int x,val;
		scanf("%d%d",&x,&val);
		if(x==pos)num1++;
		else num2++;
		if(val<v)flag=0;
		if(val>v)flag=1;
	}
	if(flag==1)printf("! %d\n",num2);
	else printf("! %d\n",num1+1);
	return 0;
}