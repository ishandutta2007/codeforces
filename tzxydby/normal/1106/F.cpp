#include<bits/stdc++.h>
using namespace std;
const int N=105,mod=998244353;
struct mat{int a[N][N],x,y;}s,t;
unordered_map<int,int>mp;
int k,n,m;
mat operator*(mat x,mat y)
{
	mat z;
	z.x=x.x,z.y=y.y;
	for(int i=1;i<=z.x;i++)
	{
		for(int j=1;j<=z.y;j++)
		{
			z.a[i][j]=0;
			for(int k=1;k<=x.y;k++)
				z.a[i][j]=(1ll*z.a[i][j]+1ll*x.a[i][k]*y.a[k][j])%(mod-1);
		}
	}
	return z;
}
mat qp(mat a,int b)
{
	mat ans=a;
	b--;
	while(b)
	{
		if(b&1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int g=exgcd(b,a%b,x,y),t=x;
	x=y,y=t-a/b*y;
	return g;
}
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int bsgs()
{
	int b=32767,t=m%mod,pw=qp(3,b);
	for(int i=0;i<b;i++)
	{
		mp[t]=i;
		t=1ll*t*3%mod;
	}
	t=1;
	for(int i=0;i<b;i++)
	{
		if(mp.find(t)!=mp.end())
			return i*b-mp[t];
		t=1ll*t*pw%mod;
	}
}
int main()
{
	scanf("%d",&k);
	s.x=1,s.y=t.x=t.y=k;
	s.a[1][k]=1;
	for(int i=2;i<=k;i++)
		t.a[i][i-1]=1;
	for(int i=k;i>=1;i--)
		scanf("%d",&t.a[i][k]);
	scanf("%d%d",&n,&m);
	s=s*qp(t,n-k);
	m=bsgs();
	int x,y,g=exgcd(s.a[1][k],mod-1,x,y);
	x=(x%(mod-1)+mod-1)%(mod-1);
	if(m%g)
		puts("-1");
	else
		printf("%d\n",qp(3,1ll*m/g*x%(mod-1)));
	return 0;
}