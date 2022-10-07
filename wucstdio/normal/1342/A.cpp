#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll x,y,a,b;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		if(b<a*2)printf("%lld\n",min(x,y)*b+(max(x,y)-min(x,y))*a);
		else printf("%lld\n",(x+y)*a);
	}
	return 0;
}