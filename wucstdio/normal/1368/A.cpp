#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&n);
		int ans=0;
		while(a<=n&&b<=n)
		{
			if(a>b)swap(a,b);
			a+=b;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}