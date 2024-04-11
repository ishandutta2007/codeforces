#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll t,k,n,a,b;
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d%I64d",&k,&n,&a,&b);
		k-=b*n;
		if(k<=0)
		{
			printf("-1\n");
			continue;
		}
		printf("%I64d\n",min((k-1)/(a-b),n));
	}
	return 0;
}