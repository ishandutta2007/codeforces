#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char str[2000005];
char s[2000005];
int rd[2000005];
bool vis[2000005];
queue<int>que;
signed main()
{
	int t,n,m,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str+1);
			for(int j=(i-1)*m+1;j<=i*m;j++)s[j]=str[j-(i-1)*m];
		}
		for(int i=1;i<=n*m;i++)
		{
			if(s[i]=='L')
			{
				x=i;
				break;
			}
		}
		for(int i=1;i<=n*m;i++)
		{
			rd[i]=0;
			vis[i]=false;
			if((i-1)%m>=1&&s[i-1]!='#')rd[i]++;
			if((i-1)%m<=m-2&&s[i+1]!='#')rd[i]++;
			if(i>=m+1&&s[i-m]!='#')rd[i]++;
			if(i<=(n-1)*m&&s[i+m]!='#')rd[i]++;
			//printf("%d %d\n",i,rd[i]);
		}
		que.push(x);
		vis[x]=true; 
		while(!que.empty())
		{
			x=que.front();
			que.pop();
			if((x-1)%m>=1&&s[x-1]=='.'&&vis[x-1]==false)
			{
				rd[x-1]--;
				if(rd[x-1]<=1)vis[x-1]=true,que.push(x-1);
			}
			if((x-1)%m<=m-2&&s[x+1]=='.'&&vis[x+1]==false)
			{
				rd[x+1]--;
				if(rd[x+1]<=1)vis[x+1]=true,que.push(x+1);
			}
			if(x>=m+1&&s[x-m]=='.'&&vis[x-m]==false)
			{
				rd[x-m]--;
				if(rd[x-m]<=1)vis[x-m]=true,que.push(x-m);
			}
			if(x<=(n-1)*m&&s[x+m]=='.'&&vis[x+m]==false)
			{
				rd[x+m]--;
				if(rd[x+m]<=1)vis[x+m]=true,que.push(x+m);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[(i-1)*m+j]=='L')printf("L");
				else if(s[(i-1)*m+j]=='#')printf("#");
				else if(vis[(i-1)*m+j]==true)printf("+");
				else printf(".");
			}
			printf("\n");
		}
	} 
	return 0;
}