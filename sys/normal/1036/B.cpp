#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
int q;
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		if(((m>k)||((m==k)&&((m-k)%2)))||((n>k)||((n==k)&&((n-k)%2)))){printf("-1\n");continue;}
		if((n+m)%2) k--;
		else
			if((k-m)%2) k-=2;
		printf("%lld\n",k);
	}
	return 0;
}