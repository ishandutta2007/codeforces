#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[1005],b[1005],n,pos[2005],qz[2005];
bool bi(int x,int y)
{
	return qz[x]<qz[y];
}
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
bool visa[1005],visb[1005];
int h[1005],cnt;
bool check(int k)
{
	for(int i=1;i<=n;i++)
	{
		visa[i]=false;
		visb[i]=false;
	}
	int x=n,y=n,now;
	cnt=0;
	for(int i=2*n;i>=1;i--)
	{
		if(qz[pos[i]]<k)break;
		if(pos[i]<=n)
		{
			now=pos[i];
			if(visa[now])continue;
			while(y>=1&&(visb[y]==true||a[now]-b[y]<k))y--;
			//printf("%lld %lld\n",now,y);
			if(y==0)return false;
			if(visb[y]==true||a[now]-b[y]!=k)return false;
			visa[now]=true;
			visb[y]=true;
			h[++cnt]=a[now];
		}
		else
		{
			now=pos[i]-n;
			if(visb[now])continue;
			while(x>=1&&(visa[x]==true||b[now]-a[x]<k))x--;
			//printf("%lld %lld\n",now,x);
			if(x==0)return false;
			if(visa[x]==true||b[now]-a[x]!=k)return false;
			visb[now]=true;
			visa[x]=true;
			h[++cnt]=k-b[now];
		}
	}
	x=n;
	y=n;
	for(int i=1;i<=2*n;i++)
	{
		if(pos[i]<=n)
		{
			now=pos[i];
			if(visa[now])continue;
			while(y>=1&&(visb[y]==true||b[y]>k-a[now]))y--;
			if(y==0)return false;
			if(visb[y]==true||b[y]!=k-a[now])return false;
			visa[now]=true;
			visb[y]=true;
			h[++cnt]=a[now];
		}
		else
		{
			now=pos[i]-n;
			if(visb[now])continue;
			while(x>=1&&(visa[x]==true||a[x]>k-b[now]))x--;
			if(x==0)return false;
			if(visa[x]==true||a[x]!=k-b[now])return false;
			visb[now]=true;
			visa[x]=true;
			h[++cnt]=a[x];
		}
	}
	printf("YES\n");
	int minn=0;
	for(int i=1;i<=n;i++)minn=min(minn,h[i]);
	for(int i=1;i<=cnt;i++)printf("%lld ",h[i]-minn);
	printf("\n");
	printf("%lld %lld\n",-minn,k-minn);
	return true;
}
signed main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)qz[i]=a[i];
		for(int i=1;i<=n;i++)qz[i+n]=b[i];
		for(int i=1;i<=2*n;i++)pos[i]=i;
		sort(pos+1,pos+2*n+1,bi);
		//printf("%lld\n",pos[4]);
		bool flag=false;
		//check(11);
		for(int i=1;i<=n;i++)
		{
			if(check(a[1]+b[i]))
			{
				flag=true;
				break;
			}
			if(check(jdz(a[1]-b[i])))
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
	}
	return 0;
}