#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll a,b,n,m,sum,sum1,use[100005];
int ans1[100005],top;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	while(sum1<=a)sum1+=++n;
	sum1-=n--;
	while(sum<=a+b)sum+=++m;
	sum-=m--;
	sum1=a-sum1;
	if(n==0)
	{
		printf("0\n\n");
		printf("%d\n",m);
		for(int i=1;i<=m;i++)
		  printf("%d ",i);
		printf("\n");
		return 0;
	}
	if(n==m)
	{
		printf("%d\n",m);
		for(int i=1;i<=m;i++)
		  printf("%d ",i);
		printf("\n");
		printf("0\n\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(n-i+1<=sum1)ans1[++top]=i+1;
		else ans1[++top]=i;
		use[ans1[top]]=1;
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
	  printf("%d ",ans1[i]);
	printf("\n");
	printf("%d\n",m-top);
	for(int i=1;i<=m;i++)
	  if(!use[i])printf("%d ",i);
	printf("\n");
	return 0;
}