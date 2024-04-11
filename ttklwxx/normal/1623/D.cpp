#include<iostream>
#include<cstdio>
#define mod 1000000007
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
int vis[400005][2][2];
int tans[1000005],cnt;
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
signed main()
{
	int t,n,m,x1,y1,x2,y2,tx,ty,ans,bs=0,gre=0,p,cm;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		p=read();
		p=1LL*p*ksm(100,mod-2)%mod;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[(i-1)*m+j][0][0]=-1;
				vis[(i-1)*m+j][0][1]=-1;
				vis[(i-1)*m+j][1][0]=-1;
				vis[(i-1)*m+j][1][1]=-1;
			}
		}
		tx=1;
		ty=1;
		if(x1+tx>n||x1+tx<=0)tx=-tx;
		if(y1+ty>m||y1+ty<=0)ty=-ty;
		vis[(x1-1)*m+y1][(tx+1)/2][(ty+1)/2]=0;
		ans=0;
		cnt=0;
		if(x1==x2||y1==y2)tans[++cnt]=0;
		while(1)
		{
			x1+=tx;
			y1+=ty;
			if(x1+tx>n||x1+tx<=0)tx=-tx;
			if(y1+ty>m||y1+ty<=0)ty=-ty;
			ans++;
			if(vis[(x1-1)*m+y1][(tx+1)/2][(ty+1)/2]!=-1)
			{
				bs=ans-vis[(x1-1)*m+y1][(tx+1)/2][(ty+1)/2];
				break;
			}
			vis[(x1-1)*m+y1][(tx+1)/2][(ty+1)/2]=ans;
			if(x1==x2||y1==y2)tans[++cnt]=ans;
		}
		gre=0;
		cm=ksm(mod+1-p,cnt);
		cm=ksm(mod+1-cm,mod-2);
		//printf("%lld %lld\n",bs,cnt);
		for(int i=1;i<=cnt;i++)
		{
			//printf("%lld\n",tans[i]); 
			if(tans[i]==0)
			{
				gre=(gre+1LL*bs*ksm(mod+1-p,i-1)%mod*p%mod*cm%mod*cm%mod*ksm(mod+1-p,cnt)%mod)%mod;
				//printf("%lld\n",gre);
				continue;
			}
			int cj=1LL*ksm(mod+1-p,i-1)*p%mod*tans[i]%mod;
			int sth=1LL*bs*ksm(tans[i],mod-2)%mod;
			gre=(gre+1LL*cj*cm%mod+1LL*cj*sth%mod*cm%mod*cm%mod*ksm(mod+1-p,cnt))%mod;
			//printf("%lld\n",gre);
		}
		printf("%lld\n",gre);
	} 
	return 0;
}