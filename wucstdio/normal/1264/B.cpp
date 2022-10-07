#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int c[4];
int main()
{
	scanf("%d%d%d%d",&c[0],&c[1],&c[2],&c[3]);
	if(c[0]==0)
	{
		if(c[2]!=c[1]+c[3]&&c[2]!=c[1]+c[3]-1&&c[2]!=c[1]+c[3]+1)
		{
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		int now=1;
		if(!c[1])now=3;
		if(c[2]==c[1]+c[3]+1)now=2;
		while(c[1]+c[2]+c[3])
		{
			printf("%d ",now);
			c[now]--;
			if(c[now-1])now--;
			else now++;
		}
		printf("\n");
		return 0;
	}
	if(c[3]==0)
	{
		if(c[1]!=c[0]+c[2]&&c[1]!=c[0]+c[2]-1&&c[1]!=c[0]+c[2]+1)
		{
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		int now=0;
		if(c[1]==c[0]+c[2]+1)now=1;
		while(c[0]+c[1]+c[2])
		{
			printf("%d ",now);
			c[now]--;
			if(c[now+1])now++;
			else now--;
		}
		printf("\n");
		return 0;
	}
	if(c[1]<c[0]||c[2]<c[3])
	{
		printf("NO\n");
		return 0;
	}
	if(c[1]-c[0]==c[2]-c[3])
	{
		printf("YES\n");
		int now=0;
		while(c[0]+c[1]+c[2]+c[3])
		{
			printf("%d ",now);
			c[now]--;
			if(now&&c[now-1])now--;
			else now++;
		}
		printf("\n");
		return 0;
	}
	if(c[1]-c[0]==c[2]-c[3]+1)
	{
		printf("YES\n");
		int now=1;
		while(c[0]+c[1]+c[2]+c[3])
		{
			printf("%d ",now);
			c[now]--;
			if(now&&c[now-1])now--;
			else now++;
		}
		printf("\n");
		return 0;
	}
	if(c[1]-c[0]==c[2]-c[3]-1)
	{
		printf("YES\n");
		int now=0;
		while(c[0]+c[1]+c[2]+c[3])
		{
			printf("%d ",now);
			c[now]--;
			if(now&&c[now-1])now--;
			else now++;
		}
		printf("\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}