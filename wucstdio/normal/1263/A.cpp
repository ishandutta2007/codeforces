#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a+b+c-max(max(a,b),c)<max(max(a,b),c))printf("%d\n",a+b+c-max(max(a,b),c));
		else printf("%d\n",(a+b+c)/2);
	}
	return 0;
}