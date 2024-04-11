#include <bits/stdc++.h>
using namespace std;
long long n,l,r;
int main()
{
	scanf("%I64d",&n);
	l=1;
	r=n;
	while(l<r)
	{
		long long mid=(l+r)/2,now=n,ate=0;
		while(now>=mid)
		{
			now-=mid;
			now=now-(long long)(now/10.0);
			ate+=mid; 
		}
		ate+=now;
		if(ate*2>=n) r=mid;
		else l=mid+1;
	}
	printf("%I64d",l);
	return 0;
}