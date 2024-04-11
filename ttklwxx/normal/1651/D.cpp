#include<iostream>
#include<cstdio>
#include<queue>
#include<unordered_map>
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
int tx[200005],ty[200005];
bool vis[200005];
int ansx[200005],ansy[200005];
unordered_map<int,int>ma;
queue<int>que;
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)
	{
		tx[i]=read();
		ty[i]=read();
		ma[tx[i]*200000+ty[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(ma[(tx[i]-1)*200000+ty[i]]==0)
		{
			vis[i]=true;
			ansx[i]=tx[i]-1;
			ansy[i]=ty[i];
			que.push(i);
		}
		else if(ma[(tx[i]+1)*200000+ty[i]]==0)
		{
			vis[i]=true;
			ansx[i]=tx[i]+1;
			ansy[i]=ty[i];
			que.push(i);
		}
		else if(ma[(tx[i])*200000+ty[i]-1]==0)
		{
			vis[i]=true;
			ansx[i]=tx[i];
			ansy[i]=ty[i]-1;
			que.push(i);
		}
		else if(ma[(tx[i])*200000+ty[i]+1]==0)
		{
			vis[i]=true;
			ansx[i]=tx[i];
			ansy[i]=ty[i]+1;
			que.push(i);
		}
	}
	int x;
	while(!que.empty())
	{
		int i=que.front();
		que.pop();
		if(ma[(tx[i]-1)*200000+ty[i]]!=0)
		{
			int sth=ma[(tx[i]-1)*200000+ty[i]];
			if(vis[sth]==false)
			{
				ansx[sth]=ansx[i];
				ansy[sth]=ansy[i];
				vis[sth]=true;
				que.push(sth);
			}
		}
		if(ma[(tx[i]+1)*200000+ty[i]]!=0)
		{
			int sth=ma[(tx[i]+1)*200000+ty[i]];
			if(vis[sth]==false)
			{
				ansx[sth]=ansx[i];
				ansy[sth]=ansy[i];
				vis[sth]=true;
				que.push(sth);
			}
		}
		if(ma[(tx[i])*200000+ty[i]-1]!=0)
		{
			int sth=ma[(tx[i])*200000+ty[i]-1];
			if(vis[sth]==false)
			{
				ansx[sth]=ansx[i];
				ansy[sth]=ansy[i];
				vis[sth]=true;
				que.push(sth);
			}
		}
		if(ma[(tx[i])*200000+ty[i]+1]!=0)
		{
			int sth=ma[(tx[i])*200000+ty[i]+1];
			if(vis[sth]==false)
			{
				ansx[sth]=ansx[i];
				ansy[sth]=ansy[i];
				vis[sth]=true;
				que.push(sth);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld %lld\n",ansx[i],ansy[i]);
	}
	return 0;
}