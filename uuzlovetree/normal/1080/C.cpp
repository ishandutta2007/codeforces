#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll n,m;
ll ax,ay,bx,by,cx,cy,dx,dy;
ll calcw(ll n,ll m,ll col)//white 0 black 1 
{
	ll t=n*m;
	if(t%2==0)return t/2;
	else return t/2+(1-col);
}
ll calcb(ll n,ll m,ll col)
{
	ll t=n*m;
	if(t%2==0)return t/2;
	else return t/2+col;
}
bool out()
{
	return (bx<cx||ax>dx||by<cy||ay>dy);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&n,&m);
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
		if(out())
		{
			ll ans1=calcw(m,n,0);
			ans1=ans1+calcb(bx-ax+1,by-ay+1,(ax+ay)&1)-calcw(dx-cx+1,dy-cy+1,(cx+cy)&1);
			ll ans2=m*n-ans1;
			printf("%I64d %I64d\n",ans1,ans2);
		}
		else
		{
			ll xmin=max(ax,cx),ymin=max(ay,cy);
			ll xmax=min(bx,dx),ymax=min(by,dy);
			ll ans1=calcw(m,n,0);
			ans1=ans1+calcb(bx-ax+1,by-ay+1,(ax+ay)&1)-calcb(xmax-xmin+1,ymax-ymin+1,(xmin+ymin)&1)-calcw(dx-cx+1,dy-cy+1,(cx+cy)&1);
			ll ans2=m*n-ans1;
			printf("%I64d %I64d\n",ans1,ans2);
		}
	}
	return 0;
}