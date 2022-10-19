#include<bits/stdc++.h>
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
int a[300005],b[300005];
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
int sth;
void exgcd(int a,int b,int& tx,int& ty)
{
	if(b==0)
	{
		tx=sth;
		ty=0;
		return;
	}
	exgcd(b,a%b,ty,tx);
	ty-=tx*(a/b);
	if(tx<=0)
	{
		ty-=(abs(tx)/b+1)*a;
		tx+=(abs(tx)/b+1)*b; 
	}
	if(tx>b)
	{
		ty+=(tx-1)/b*a;
		tx-=(tx-1)/b*b;
	}
}
int qans[300005];
bool bi(int x,int y)
{
	return x>y;
}
signed main()
{
	int n,m,ans=0,x,y;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=read();
		ans+=a[i];
		a[i]=b[i]-a[i];
	}
	sort(a+1,a+n+1,bi);
	int pos=0;
	while(pos<=n-1&&a[pos+1]>0)pos++;
	qans[0]=ans;
	for(int i=1;i<=n;i++)qans[i]=qans[i-1]+a[i];
	//printf("???%d\n",qans[n]);
	m=read();
	int gc,tx,ty,ca,tans,now;
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		gc=gcd(x,y);
		if(n%gc!=0)
		{
			printf("-1\n");
			continue;
		}
		sth=n/gc;
		exgcd(x/gc,y/gc,tx,ty);
		if(tx==y/gc)
		{
			tx-=y/gc;
			ty+=x/gc;
		}
		//printf("orz%lld %lld\n",tx,ty);
		if(ty<0)
		{
			printf("-1\n");
			continue;
		}
		ca=x*y/gc;
		ty*=y;
		tans=-1;
		if(pos>ty)
		{
			now=ty+(pos-ty+ca-1)/ca*ca;
		}
		else
		{
			now=ty-(ty-pos)/ca*ca;
		}
		//printf("!!!%d\n",now);
		if(now<=n&&now>=0)tans=max(tans,qans[now]);
		now-=ca;
		if(now>=0&&now<=n)tans=max(tans,qans[now]);
		//printf("!!!%d\n",now);
		printf("%lld\n",tans);
	}
	return 0;
}