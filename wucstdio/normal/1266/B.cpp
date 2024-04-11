#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&x);
		if(x<=14||x%14==0||x%14>6)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}