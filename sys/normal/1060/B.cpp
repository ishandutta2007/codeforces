#include <bits/stdc++.h>
using namespace std;
long long n,maxi;
int cnt;
int main()
{
	scanf("%lld",&n);
	for(maxi=0;maxi*10+9<=n;maxi=maxi*10+9)cnt+=9;
	n-=maxi;
	while(n)
	{
		cnt+=n%10;
		n/=10;
	}
	printf("%d",cnt);
	return 0;
}