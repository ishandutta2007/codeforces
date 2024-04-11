#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n,k;
	int a[60];
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	if(a[k-1]==0)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=0) cnt++;
		}
		printf("%d\n",cnt);
		return 0;
	}
	int cnt=k;
	for(int i=k;i<n;i++)
	{
		if(a[i]==a[k-1]) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}