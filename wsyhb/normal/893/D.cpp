#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	int l=0,r=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		if(x!=0)
		{
			l+=x,r+=x;
			if(l>d)
			{
				puts("-1");
				return 0;
			}
			r=min(r,d);
		}
		else
		{
			if(r<0)
			{
				l=0,r=d;
				++ans;
			}
			else
				l=max(l,0);
		}
	}
	printf("%d\n",ans);
	return 0;
}