#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue> 
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
priority_queue<int>que;
int cz1[200005],cz2[200005];
signed main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)que.push(i);
		for(int i=1;i<=n-1;i++)
		{
			cz1[i]=que.top();
			que.pop();
			cz2[i]=que.top();
			que.pop();
			que.push((cz1[i]+cz2[i]+1)/2);
		}
		printf("%d\n",que.top());
		que.pop();
		for(int i=1;i<=n-1;i++)printf("%d %d\n",cz1[i],cz2[i]);
	}
	return 0;
}