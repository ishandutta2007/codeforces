#include<bits/stdc++.h>
using namespace std;
inline int dis(int x,int y,int a,int b)
{
	return max(x-a,a-x)+max(y-b,b-y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,sx,sy,d;
		scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&d);
		bool ok=true;
		for(int i=1;i<=n;++i)
		{
			if(dis(i,1,sx,sy)<=d)
			{
				ok=false;
				break;
			}
		}
		for(int i=1;i<=m;++i)
		{
			if(dis(n,i,sx,sy)<=d)
			{
				ok=false;
				break;
			}
		}
		if(!ok)
		{
			ok=true;
			for(int i=1;i<=n;++i)
			{
				if(dis(i,m,sx,sy)<=d)
				{
					ok=false;
					break;
				}
			}
			for(int i=1;i<=m;++i)
			{
				if(dis(1,i,sx,sy)<=d)
				{
					ok=false;
					break;
				}
			}
		}
		if(ok)
			printf("%d\n",n+m-2);
		else
			puts("-1"); 
	}
	return 0;
}