#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b;
int calc(int a,int b)
{
	if(b==1)return 100000;
	int ans=0;
	while(a)
	{
		ans++;
		a/=b;
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		int ans=calc(a,b);
		for(int i=b+1;i<=b+30;i++)
			ans=min(ans,calc(a,i)+i-b);
		printf("%d\n",ans);
	}
	return 0;
}