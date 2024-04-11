#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int T;
ll x,y;
ll c1,c2,c3,c4,c5,c6;
ll a[8][8];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		scanf("%lld%lld%lld%lld%lld%lld",&c1,&c2,&c3,&c4,&c5,&c6);
		while(1)
		{
			ll p2,p3,p5,p6;
			p2=min(c2,c1+c3);
			p3=min(c3,c2+c4);
			p5=min(c5,c4+c6);
			p6=min(c6,c1+c5);
			if(c2==p2&&c3==p3&&c5==p5&&c6==p6)break;
			c2=p2;c3=p3;c5=p5;c6=p6;
		}
		ll ans=0;
		if(x>0)ans+=x*c6;else ans+=(-x)*c3;
		if(y>0)ans+=y*c2;else ans+=(-y)*c5;
		if(x>0)
		{
			ll res=0;
			res+=x*c1;
			if(y<x)res+=c5*(x-y);
			else res+=c2*(y-x);
			ans=min(ans,res);
		}
		else
		{
			ll res=0;
			res+=(-x)*c4;
			if(y<x)res+=c5*(x-y);
			else res+=c2*(y-x);
			ans=min(ans,res);
		}
		if(y>0)
		{
			ll res=0;
			res+=y*c1;
			if(x<y)res+=c3*(y-x);
			else res+=c6*(x-y);
			ans=min(ans,res);
		}
		else
		{
			ll res=0;
			res+=(-y)*c4;
			if(x<y)res+=c3*(y-x);
			else res+=c6*(x-y);
			ans=min(ans,res);
		}
		printf("%lld\n",ans);
	}
}