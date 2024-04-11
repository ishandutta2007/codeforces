#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll x,y,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		printf("%lld\n",(y-x)%(a+b)==0?(y-x)/(a+b):-1);
	}
	return 0;
}