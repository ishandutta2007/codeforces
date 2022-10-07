#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,k,a[200005];
int main()
{
	scanf("%d%d",&n,&k);
	if(k==3&&n==8)
	{
		printf("NO\n");
		return 0;
	}
	if(k==2&&n==4)
	{
		printf("NO\n");
		return 0;
	}
	if(n<1ll*k*(k+1)/2)
	{
		printf("NO\n");
		return 0;
	}
	int st=(n-k*(k-1)/2)/k;
	for(int i=1;i<=k;i++)
	{
		a[i]=st+i-1;
		n-=a[i];
	}
	for(int i=k;i>=1;i--)
	{
		if(n==0)break;
		a[i]++,n--;
	}
	if(a[1]==1&&a[2]==3)a[2]--,a[k]++;
	printf("YES\n");
	for(int i=1;i<=k;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}