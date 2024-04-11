#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int q;
int maxx(int x)
{
	if(x<=1)return x;
	while(x&(x-1))x=(x-1)&x;
	return x;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		while(u&&maxx(u)==maxx(v))
		{
			int x=maxx(u);
			u-=x;
			v-=x;
		}
		if(!u&&!v)
		{
			printf("Yes\n");
			continue;
		}
		if(!u||!v)
		{
			printf("No\n");
			continue;
		}
		if(u>v)
		{
			printf("No\n");
			continue;
		}
		int t=0;
		bool flag=1;
		for(int i=0;i<30;i++)
		{
			if((1<<i)&u)t++;
			if((1<<i)&v)t--;
			if(t<0)
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}