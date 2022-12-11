#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55+5;
ll x[N],y[N];
ll dis(ll a,ll b,ll c,ll d)
{
	return abs(a-c)+abs(b-d);
}
int main()
{
	ll ax,ay,bx,by,xs,ys,t;
	scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&xs,&ys,&t);
	int n=55;
	for(int i=1;i<=55;i++)
	{
		x[i]=ax*x[i-1]+bx;
		y[i]=ay*y[i-1]+by;
		if(x[i]<x[i-1]||y[i]<y[i-1])
		{
			n=i-1;
			break;
		}
	}
	int Max=0;
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			ll ans=2e16;
			for(int k=i;k<=j;k++)
				ans=min(ans,dis(xs,ys,x[k],y[k])+dis(x[i],y[i],x[j],y[j])+min(dis(x[k],y[k],x[i],y[i]),dis(x[k],y[k],x[j],y[j])));
			if(ans<=t&&ans>=0) Max=max(Max,j-i+1);
		}
	printf("%d",Max);
	return 0;
}