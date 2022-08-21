#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll n,m;
typedef pair<ll,ll> pll;
#define fi first
#define se second
//<=qr 
bool work(ll x,ll c0,ll c1,ll rm,ll q0,ll q1,ll qr,pll s)
{
	//cout<<"work"<<x<<","<<c0<<","<<c1<<","<<rm<<","<<q0<<","<<q1<<","<<qr<<","<<s.fi<<","<<s.se<<"\n";
	//system("pause");
	if(x==2)
	{
	if(rm<=c1)
	{
		ll p=(s.fi-1)/2+s.se;
		if(p<=qr)
		{
			if(s.fi==x) ++q0; else ++q1;
		}
		return rm<=q1;
	}
	map<ll,ll> ms; ms[x]+=c0;
	ms[x/2]+=c1; ms[(x+1)/2]+=c1;
	ll pp=1,X=ms[pp],Y=ms[pp+1]; ms.clear();
	ms[x]+=q0; ms[x/2]+=q1; ms[(x+1)/2]+=q1;
	ll Z=ms[pp],W=ms[pp+1]; ms.clear();
	if(s.fi==3)
	{
	pll A((s.fi-1)/2,s.se),B(s.fi/2,s.se+(s.fi+1)/2);
	if(B.se>qr) s=A;
	else {s=B; if(A.fi==pp) ++Z; else ++W;}
	}
	return work(pp,X,Y,rm-c1,Z,W,qr,s);
	}
	if(x==1&&c1) //expand
	{
		c0+=c1*2; c1=0; q0+=q1*2; q1=0;
		if(s.fi==2)
		{
			pll A(1,s.se),B(1,s.se+1);
			if(B.se>qr) s=A;
			else s=B, ++q0;
		}
		return work(1,c0,0,rm,q0,0,qr,s);
	}
	if(rm<=c0+c1)
	{
		//for 4,5  5 first
		//for 5,6  any
		ll p=(s.fi-1)/2+s.se;
		if(p<=qr)
		{
			if(s.fi==x) ++q0; else ++q1;
		}
		if(x%2==0)
		{
			//c1
			if(rm<=c1) return rm<=q1;
			return rm-c1<=q0;
		}
		return rm<=q0+q1;
	}
	map<ll,ll> ms;
	ms[(x-1)/2]+=c0; ms[x/2]+=c0;
	ms[x/2]+=c1; ms[(x+1)/2]+=c1;
	ll pp;
	for(map<ll,ll>::iterator g
	=ms.begin();g!=ms.end();++g) if(g->se)
	{pp=g->fi; break;}
	ll X=ms[pp],Y=ms[pp+1]; ms.clear();
	ms[(x-1)/2]+=q0; ms[x/2]+=q0;
	ms[x/2]+=q1; ms[(x+1)/2]+=q1;
	ll Z=ms[pp],W=ms[pp+1]; ms.clear();
	pll A((s.fi-1)/2,s.se),B(s.fi/2,s.se+(s.fi+1)/2);
	if(B.se>qr) s=A;
	else {s=B; if(A.fi==pp) ++Z; else ++W;}
	return work(pp,X,Y,rm-c0-c1,Z,W,qr,s);
}
bool ok(ll s)
{
	//cout<<"ok"<<s<<"\n";
	return work(n-2,1,0,m,0,0,s,pll(n-2,2));
}
int main()
{
	scanf("%lld%lld",&n,&m);
	if(m==1)
	{
		puts("1");
		return 0;
	}
	if(m==2)
	{
		printf("%lld\n",n);
		return 0;
	}
	m-=2;
	ll l=2,r=n-1;
	while(l<r)
	{
		ll g=(l+r)>>1;
		if(ok(g)) r=g; else l=g+1;
	}
	printf("%lld\n",l);
}