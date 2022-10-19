#include<bits/stdc++.h>
using namespace std;
const int inf=2e9;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,xl,xr,yl,yr,x,y,v;
		scanf("%d%d%d%d%d%d%d%d",&n,&m,&xl,&yl,&xr,&yr,&x,&y);
		int xd,yd,ans=inf;
		if(xl>=x)
			ans=min(ans,0);
		else
		{
			v=x-xl;
			if(xr+v<=n)
				ans=min(ans,v);
		}
		if(xr<=n-x)
			ans=min(ans,0);
		else
		{
			v=xr-(n-x);
			if(xl-v>=0)
				ans=min(ans,v);
		}
		if(yl>=y)
			ans=min(ans,0);
		else
		{
			v=y-yl;
			if(yr+v<=m)
				ans=min(ans,v);
		}
		if(yr<=m-y)
			ans=min(ans,0);
		else
		{
			v=yr-(m-y);
			if(yl-v>=0)
				ans=min(ans,v);
		}
		if(ans==inf)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}