#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,c[10005],ans,ans2;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
		ans=max(ans,x);
	}
	printf("%d ",ans);
	for(int i=1;i<=ans;i++)
	{
		if(ans%i==0)c[i]--;
		if(c[i]==1)ans2=max(ans2,i);
	}
	printf("%d\n",ans2);
	return 0;
}