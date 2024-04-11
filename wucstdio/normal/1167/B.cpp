#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int a[6]={4,8,15,16,23,42};
int ans[6];
bool flag[6];
int main()
{
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d",&ans[0]);
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d",&ans[1]);
	printf("? 4 5\n");
	fflush(stdout);
	scanf("%d",&ans[2]);
	printf("? 5 6\n");
	fflush(stdout);
	scanf("%d",&ans[3]);
	printf("! ");
	bool flag=0;
	for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
	for(int k=0;k<6;k++)
	{
		if(flag)break;
		if(i==j||j==k||i==k)continue;
		if(a[i]*a[j]==ans[0]&&a[j]*a[k]==ans[1])
		{
			printf("%d %d %d ",a[i],a[j],a[k]);
			flag=1;
			break;
		}
	}
	for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
	for(int k=0;k<6;k++)
	{
		if(i==j||j==k||i==k)continue;
		if(a[i]*a[j]==ans[2]&&a[j]*a[k]==ans[3])
		{
			printf("%d %d %d\n",a[i],a[j],a[k]);
			fflush(stdout);
			return 0;
		}
	}
	fflush(stdout);
	return 0;
}