#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,m,k,a[N],b[N],pa[N],pb[N],g,l,p[N];
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y);
	int t=x;x=y,y=t-a/b*y;
	return r;
}
int check(int w)
{
	int s=w+1;
	for(int i=1;i<=2*max(n,m);i++)
		if(p[i]>=0&&p[i]<=w)
			s-=(w-p[i])/l+1;
	return s>=k;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=2*max(n,m);i++)
		pa[i]=pb[i]=-1;
	for(int i=0;i<n;i++)
		cin>>a[i],pa[a[i]]=i;
	for(int i=0;i<m;i++)
		cin>>b[i],pb[b[i]]=i;
	g=__gcd(n,m);
	l=n*m/g;
	for(int i=1;i<=2*max(n,m);i++)
	{
		if(pa[i]==-1||pb[i]==-1)
		{
			p[i]=-1;
			continue;
		}
		int x,y;
		int r=(pb[i]-pa[i]);
		if(r%g)
		{
			p[i]=-1;
			continue;
		}
		exgcd(n,m,x,y);
		x*=r/g;
		p[i]=(n*x+pa[i])%l;
		if(p[i]<0)
			p[i]+=l;
	}
	int l=0,r=2e18;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l+1<<endl;
	return 0;
}