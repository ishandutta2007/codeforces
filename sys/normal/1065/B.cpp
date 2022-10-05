#include <bits/stdc++.h>
using namespace std;
int n,now,maxi;
long long m,mini;
int main()
{
	scanf("%d%lld",&n,&m);
	mini=n-m*2;
	for(int i=0;i<=n;i++)
		if((long long)i*(i-1)/2>=m)
		{
			maxi=n-i;
			break;
		}
	printf("%d %d",mini<0?0:(int)mini,maxi);
	return 0;
}