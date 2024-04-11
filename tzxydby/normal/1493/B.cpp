#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
using namespace std;
struct cloc{
	ll hh,mm;
}ori,nw;
ll T,n,m,canp[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
char s[10];
cloc get_nxt(cloc x)
{
	x.mm++;
	if(x.mm>=m)
	{
		x.hh++;
	}
	x.hh%=n;
	x.mm%=m;
	return x;
}
bool check(cloc x)
{
	ll nx,ny;
	if(canp[x.hh/10]!=-1&&canp[x.hh%10]!=-1&&canp[x.mm/10]!=-1&&canp[x.mm%10]!=-1)
	{
		nx=canp[x.mm/10]+canp[x.mm%10]*10;
		ny=canp[x.hh/10]+canp[x.hh%10]*10;
		if(0<=nx&&nx<n&&0<=ny&&ny<m)
		{
			return true;
		}
		return false;
	}
	return false;
}
int main(){
	ll x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		scanf("%s",&s);
		x=(s[0]-'0')*10+(s[1]-'0');
		y=(s[3]-'0')*10+(s[4]-'0');
		ori.hh=x;
		ori.mm=y;
		nw=ori;
		if(!check(nw))
		{
			nw=get_nxt(nw);
			while(nw.hh!=ori.hh||nw.mm!=ori.mm)
			{
				if(check(nw))
				{
					break;
				}
				nw=get_nxt(nw);
			}
		}
		printf("%lld%lld:%lld%lld\n",nw.hh/10,nw.hh%10,nw.mm/10,nw.mm%10);
	}
	return 0;
}