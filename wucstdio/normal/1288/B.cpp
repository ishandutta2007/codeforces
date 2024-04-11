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
		int ans=0;
		for(int i=10;i-1<=b;i*=10)ans++;
		printf("%lld\n",1ll*ans*a);
	}
	return 0;
}