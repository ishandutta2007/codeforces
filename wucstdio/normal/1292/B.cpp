#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
}p[105];
int n;
ll xs,ys,ax,ay,bx,by,t;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&p[0].x,&p[0].y,&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&xs,&ys,&t);
	while(p[n].x+p[n].y<=4e16)
	{
		n++;
		p[n].x=p[n-1].x*ax+bx;
		p[n].y=p[n-1].y*ay+by;
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		if(abs(p[i].x-xs)+abs(p[i].y-ys)>t)continue;
		ll tt=t-abs(p[i].x-xs)-abs(p[i].y-ys),nowx=p[i].x,nowy=p[i].y;
		int res=0;
		int j=i;
		while(j>=0)
		{
			if(tt<abs(p[j].x-nowx)+abs(p[j].y-nowy))break;
			tt-=abs(p[j].x-nowx)+abs(p[j].y-nowy);
			nowx=p[j].x,nowy=p[j].y;
			res++;
			j--;
		}
		j=i+1;
		while(j<=n)
		{
			if(tt<abs(p[j].x-nowx)+abs(p[j].y-nowy))break;
			tt-=abs(p[j].x-nowx)+abs(p[j].y-nowy);
			nowx=p[j].x,nowy=p[j].y;
			res++;
			j++;
		}
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}