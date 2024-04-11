#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m;
char s[2000005],t[2000005];
ll f[2000005][2];
bool check(int v)
{
	f[0][1]=-v;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=max(f[i-1][1]-v,f[i-1][0]-2*v);
		f[i][1]=max(f[i-1][0]-v,f[i-1][1]-2*v);
		if(s[i]=='L')
		{
			f[i][0]=max(f[i][0],max(f[i-1][1]+100000000-3*v,f[i-1][0]+100000000-2*v));
			f[i][1]=max(f[i][1],max(f[i-1][0]+100000000-v,f[i-1][1]+100000000-2*v));
		}
		if(s[i]=='R')
		{
			f[i][0]=max(f[i][0],max(f[i-1][1]+100000000-v,f[i-1][0]+100000000-2*v));
			f[i][1]=max(f[i][1],max(f[i-1][0]+100000000-3*v,f[i-1][1]+100000000-2*v));
		}
	}
	return f[n][0]>=0;
}
int solve()
{
	int l=0,r=100000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	scanf("%s",t+1);
	n=(int)strlen(t+1);
	if(t[n]==t[1]&&t[n]!='X')s[++m]='X';
	for(int i=1;i<=n;i++)
	{
		if(t[i]!='X'&&t[i]==t[i-1])s[++m]='X';
		s[++m]=t[i];
	}
	swap(n,m);
	int ans=solve();
	if(t[m]==t[1]&&t[m]!='X')
	{
		for(int i=1;i<=n;i++)s[i]=s[i+1];
		s[n]='X';
		if(check(ans))ans=max(ans,solve());
	}
	printf("%lf\n",ans/1000000.0);
	return 0;
}