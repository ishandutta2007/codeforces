#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b,c,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&n);
		if((a+b+c+n)%3!=0)
		{
			printf("NO\n");
			continue;
		}
		if((a+b+c+n)/3<max(a,max(b,c)))printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}