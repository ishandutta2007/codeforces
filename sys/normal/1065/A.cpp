#include <bits/stdc++.h>
using namespace std;
int t,s,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&s,&a,&b,&c);
		printf("%lld\n",(long long)(s/c)+((long long)floor((s/c/a)))*b);
	}
	return 0;
}