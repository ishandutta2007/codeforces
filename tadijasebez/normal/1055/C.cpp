#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const ll inf=1e18;
ll sol=0;
void Try(ll la, ll ra, ll ta, ll lb, ll rb, ll tb)
{
	lb-=la;
	rb-=la;
	ra-=la;
	la-=la;
	ll dif=rb-lb;
	tb=__gcd(tb,ta);
	lb=(lb%tb+tb)%tb;
	rb=lb+dif;
	ll test=2000000;
	ll pla=la,plb=lb,pra=ra,prb=rb;
	while(test--)
	{
		sol=max(sol,min(ra,rb)-max(la,lb)+1);
		if(lb<la) lb+=tb,rb+=tb;
		else if(lb>la) la+=ta,ra+=ta;
		else lb+=tb,rb+=tb,la+=ta,ra+=ta;
		if(rb>inf || ra>inf) break;
	}
	test=2000000;
	la=pla;
	lb=plb;
	ra=pra;
	rb=prb;
	while(test--)
	{
		sol=max(sol,min(ra,rb)-max(la,lb)+1);
		if(lb<la) lb-=tb,rb-=tb;
		else if(lb>la) la-=ta,ra-=ta;
		else lb-=tb,rb-=tb,la-=ta,ra-=ta;
		if(lb<-inf || la<-inf) break;
	}
}
int main()
{
	ll la,ra,ta,lb,rb,tb;
	scanf("%lld %lld %lld",&la,&ra,&ta);
	scanf("%lld %lld %lld",&lb,&rb,&tb);
	//if(ta<tb) swap(la,lb),swap(ra,rb),swap(ta,tb);
	Try(la,ra,ta,lb,rb,tb);
	Try(lb,rb,tb,la,ra,ta);
	printf("%lld\n",sol);
	return 0;
}