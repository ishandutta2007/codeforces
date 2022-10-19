#include<iostream>
#include<cstdio>
#include<queue>
#define int long long
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
int h[200005],pos[200005];
int wz[200005],het[200005];
struct sth
{
	int id,dx;
};
bool operator<(struct sth x,struct sth y)
{
	return x.dx>y.dx;
}
priority_queue<struct sth>que;
signed main()
{
	int t,n,m,x;
	struct sth gre;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		x=read();
		for(int i=1;i<=n;i++)h[i]=read();
		while(!que.empty())que.pop();
		for(int i=1;i<=m;i++)
		{
			gre.id=i;
			gre.dx=0;
			que.push(gre);
		}
		for(int i=1;i<=n;i++)
		{
			gre=que.top();
			que.pop();
			wz[i]=gre.id;
			gre.dx+=h[i];
			que.push(gre);
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%lld ",wz[i]);
		printf("\n");
	}
	return 0;
}