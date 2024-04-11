#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0x3f3f3f3f,x;
int main()
{
	scanf("%d%d",&n,&k);
	int Max=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			if(n/i<k)
			{
				x=k*i+n/i;
				ans=min(ans,x);
			}
		}
	}
	printf("%d",ans);
	return 0;
}