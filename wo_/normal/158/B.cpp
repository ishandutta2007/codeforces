#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int num[5];
	memset(num,0,sizeof(num));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int in;
		scanf("%d",&in);
		num[in]++;
	}
	int ans=0;
	ans+=num[4];
	ans+=num[3];
	num[1]=max(0,num[1]-num[3]);
	ans+=(num[1]+2*num[2])/4;
	if((num[1]+2*num[2])%4!=0)
	{
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}