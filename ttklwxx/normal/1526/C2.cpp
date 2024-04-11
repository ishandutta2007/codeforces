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
int a[200005];
priority_queue<int,vector<int>,greater<int> >que;
signed main()
{
	int n,het=0,ans=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		que.push(a[i]);
		het+=a[i];
		ans++;
		if(het<0)
		{
			het-=que.top();
			ans--;
			que.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}