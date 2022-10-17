#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll>LL;
int n;
ll v[100020];
ll f[100020];
int c[100020];
void work(ll a,ll b)
{
	memset(f,0xc0,sizeof f);
	f[0]=0;
	LL x(0,0),y(-0x3f3f3f3f3f3f3fLL,1);
	for(int i=1;i<=n;i++)
	{
		f[c[i]]=max(f[c[i]],v[i]*a+f[c[i]]);
		if(x.Y!=c[i])
			f[c[i]]=max(f[c[i]],v[i]*b+x.X);
		else
			f[c[i]]=max(f[c[i]],v[i]*b+y.X);
		LL p(f[c[i]],c[i]);
		if(p>x)
		{
			if(x.Y==p.Y)
				x=p;
			else
				y=x,x=p;
		}
		else if(p>y)
			if(p.Y!=x.Y)
				y=p;
	}
	ll z=0;
	for (int i=0;i<=n;++i)
		z=max(z,f[i]);
	printf("%I64d\n",z);
}
int main()
{
	int q;
	cin>>n>>q;
	for (int i=1;i<=n;++i)
		scanf("%I64d",v+i);
	for (int i=1;i<=n;++i)
		scanf("%d",c+i);
	while(q--)
	{
		ll a,b;
		scanf("%I64d%I64d",&a,&b);
		work(a,b);
	}
	return 0;
}