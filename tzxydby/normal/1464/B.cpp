#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,x,y,p0,p1,s0,s1,r,ans=1e18;
char s[N];
void sol0()
{
	p0=p1=s0=s1=r=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?'||s[i]=='0')
		{
			r+=p1*y;
			p0++;
			s0++;
		}
		else
		{
			r+=p0*x;
			p1++;
			s1++;
		}
	}
	p0=p1=0;
	ans=min(ans,r);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			p0++;
			s0--;
		}
		else if(s[i]=='1')
		{
			p1++;
			s1--;
		}
		else
		{
			s0--;
			r-=p1*y;
			r-=s1*x;
			r+=p0*x;
			r+=s0*y;
			p1++;
			ans=min(ans,r);
		}
	}
}
void sol1()
{
	p0=p1=s0=s1=r=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			r+=p1*y;
			p0++;
			s0++;
		}
		else
		{
			r+=p0*x;
			p1++;
			s1++;
		}
	}
	p0=p1=0;
	ans=min(ans,r);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			p0++;
			s0--;
		}
		else if(s[i]=='1')
		{
			p1++;
			s1--;
		}
		else
		{
			s1--;
			r-=p0*x;
			r-=s0*y;
			r+=p1*y;
			r+=s1*x;
			p0++;
			ans=min(ans,r);
		}
	}
}
signed main()
{
	scanf("%s%lld%lld",s+1,&x,&y);
	n=strlen(s+1);
	sol0();
	sol1();
	printf("%lld\n",ans);
	return 0;
}