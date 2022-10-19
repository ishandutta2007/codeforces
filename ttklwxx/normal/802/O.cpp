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
int a[500005],b[500005];
struct sth
{
	int zh,id;
	sth(int x=0,int y=0)
	{
		zh=x;
		id=y;
	}
};
bool operator<(struct sth x,struct sth y)
{
	if(x.zh!=y.zh)return x.zh>y.zh;
	return x.id>y.id;
} 
priority_queue<struct sth>pq;
signed main()
{
	int n,k;
	n=read();
	k=read();
	int l=0,r=2000000000,mid;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)b[i]=read();
	while(l<=r)
	{	
		mid=(l+r)>>1;
		int tsl=0,ans=0;
		while(!pq.empty())pq.pop();
		for(int i=1;i<=n;i++)
		{
			pq.push(sth(a[i]-mid,0));
			int het=b[i]+pq.top().zh;
			if(het<0)
			{
				ans+=het;
				if(pq.top().id==0)tsl++;
				pq.pop();
				pq.push(sth(-b[i],1));
			}
		}
		if(tsl<k)l=mid+1;
		else r=mid-1;
	}
	mid=l;
	int minn=1121131433448687LL;
	int tsl=0,ans=0;
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;i++)
	{
		pq.push(sth(a[i]-mid,0));
		int het=b[i]+pq.top().zh;
		if(het<0)
		{
			ans+=het;
			if(pq.top().id==0)tsl++;
			pq.pop();
			pq.push(sth(-b[i],1));
		}
	}
	//printf("%lld %lld %lld\n",ans,tsl,mid);
	minn=min(minn,ans+k*mid);
	printf("%lld\n",minn);
	return 0;
}