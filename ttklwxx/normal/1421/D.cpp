#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long 
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
signed main()
{
	int t,c1,c2,c3,c4,c5,c6,x,y,ans,now;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		c1=read();
		c2=read();
		c3=read();
		c4=read();
		c5=read();
		c6=read();
		c1=min(c1,c2+c6);
		c2=min(c2,c1+c3);
		c3=min(c3,c4+c2);
		c4=min(c4,c3+c5);
		c5=min(c5,c4+c6);
		c6=min(c6,c1+c5);
	    ans=1000000000000000000LL;
	    now=0;
	    if(x<0)now+=-x*c3;
	    else now+=x*c6;
	    if(y<0)now+=-y*c5;
	    else now+=y*c2;
	    ans=now;
	    if(x>=0&&y>=0)
	    {
	    	if(x<=y)now=x*c1+c2*(y-x);
	    	else now=y*c1+c6*(x-y); 
	    	ans=min(ans,now);
		}
		if(x<=0&&y<=0)
		{
			x=-x;
			y=-y;
			if(x<=y)now=x*c4+c5*(y-x);
	    	else now=y*c4+c3*(x-y);
	    	ans=min(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}