#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,e,ans=0;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(d>=e)
		{
			int k=min(b,a/2);
			ans+=k*d;
			a-=k*2;
			ans+=min(c,a/2)*e;
		}
		else
		{
			int k=min(c,a/2);
			ans+=k*e;
			a-=k*2;
			ans+=min(b,a/2)*d;
		}
		printf("%d\n",ans);
	}
	return 0;
}