#include<iostream>
#include<cstdio>
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
int a[200005],qz[200005];
int st[200005][20];
int logg[200005];
int findmin(int l,int r)
{
	int x=logg[r-l+1];
	return min(st[l][x],st[r-(1<<x)+1][x]);
}
signed main()
{
	int t,n,s,maxn,mpos,l,r,mid;
	logg[1]=0;
	for(int i=2;i<=200000;i++)logg[i]=logg[i>>1]+1;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		s=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			qz[i]=a[i]+qz[i-1];
			st[i][0]=qz[i];
		}
		for(int i=1;i<=19;i++)
		{
			for(int j=1;j<=n-(1<<i)+1;j++)
			{
				st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			}
		}
		maxn=-1;
		mpos=0; 
		for(int i=1;i<=n;i++)
		{
			if(s+a[i]<0)continue;
			l=i;
			r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(findmin(i,mid)-qz[i-1]>=-s)l=mid+1;
				else r=mid-1;
			}
			//printf("%d %d %d\n",i,r,findmin(i-1,r)-qz[i-1]);
			if(r-i+1>maxn)
			{
				maxn=r-i+1;
				mpos=i;
			}
		}
		if(maxn==-1)printf("-1\n");
		else printf("%lld %lld\n",mpos,mpos+maxn-1);
	}
	
	return 0;
}