#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char s[1005][1005];
int q;
ll n,m,sum1[35],sum0[35],s1[1005][1005],s0[1005][1005];
int ask(int x)
{
	x--;
	int ans=0;
	while(x)
	{
		if(x&1)ans++;
		x>>=1;
	}
	return ans&1;
}
ll solve(int type,int k,ll x,ll y)
{
	if(x<=0||y<=0)return 0;
	if(x==(n<<k)&&y==(m<<k))
	{
		if(type==0)return sum0[k];
		else return sum1[k];
	}
	if(k==0)
	{
		if(type==0)return s0[x][y];
		else return s1[x][y];
	}
	ll ans=0;
	ans+=x%n*m*(y/m/2);
	ans+=y%m*n*(x/n/2);
	if(x%n&&y/m%2)
	{
		if(ask(x/n+1)^ask(y/m)^1)ans+=solve(type,0,x%n,m);
		else ans+=solve(type^1,0,x%n,m);
	}
	if(y%m&&x/n%2)
	{
		if(ask(x/n)^ask(y/m+1)^1)ans+=solve(type,0,n,y%m);
		else ans+=solve(type^1,0,n,y%m);
	}
	if(x%n&&y%m)
	{
		if(ask(x/n+1)^ask(y/m+1)^1)ans+=solve(type,0,x%n,y%m);
		else ans+=solve(type^1,0,x%n,y%m);
	}
	x-=x%n,y-=y%m;
	ans+=n*m*(x/n*y/m/2);
	if(x/n*y/m&1)
	{
		if(ask(x/n)^ask(y/m)^1)ans+=sum1[0];
		else ans+=sum0[0];
	}
	return ans;
}
int main()
{
	scanf("%I64d%I64d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		{
			s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1]+(s[i][j]=='1');
			s0[i][j]=s0[i-1][j]+s0[i][j-1]-s0[i-1][j-1]+(s[i][j]=='0');
		}
	}
	sum1[0]=s1[n][m];
	sum0[0]=s0[n][m];
	for(int i=1;i<=30;i++)
	{
		sum0[i]=sum0[i-1]*2+sum1[i-1]*2;
		sum1[i]=sum1[i-1]*2+sum0[i-1]*2;
	}
	while(q--)
	{
		int a1,b1,a2,b2;
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		ll nn=n,mm=m;
		int k=0;
		while(nn<a2||mm<b2)k++,nn<<=1,mm<<=1;
		printf("%I64d\n",solve(1,k,a2,b2)-solve(1,k,a1-1,b2)-solve(1,k,a2,b1-1)+solve(1,k,a1-1,b1-1));
	}
	return 0;
}