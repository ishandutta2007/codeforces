#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(a>=b)
		{
			printf("%d\n",a-b);
			continue;
		}
		int ans=2147483647;
		for(int i=0;i<b-a;i++)
			ans=min(ans,i+((a+i)|b)-b+1);
		ans=min(ans,b-a);
		for(int i=0;i<=b;i++)
			ans=min(ans,i+(a|(b+i))-(b+i)+1);
		printf("%d\n",ans);
	}
	return 0;
}