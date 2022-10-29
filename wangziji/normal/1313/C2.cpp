#include <iostream>
#define int long long
using namespace std;
struct re{
	int max1,max2,num,h,t,lazy;
	int sum;
}p[500005*4];
int b[500005];
int T,n,m;
inline void updata(int x)
{
	p[x].sum=p[x*2].sum+p[x*2+1].sum;
	p[x].max1=max(p[x*2].max1,p[x*2+1].max1);
	if(p[x*2].max1==p[x*2+1].max1)
	{
		p[x].num=p[x*2].num+p[x*2+1].num;
		p[x].max2=max(p[x*2].max2,p[x*2+1].max2);
	} else
	{
		re xx=p[x*2],yy=p[x*2+1];
		if(xx.max1<yy.max1) swap(xx,yy);
		p[x].num=xx.num;
		p[x].max2=max(xx.max2,yy.max1); 
	} 
}
#define mid (h+t)/2
void build(int x,int h,int t)
{
	p[x].h=h; p[x].t=t; p[x].lazy=2000000000;
	if(h==t)
	{ 
		p[x].max1=b[h],p[x].max2=-2000000000,p[x].num=1;
		p[x].sum=b[h];
		return;
	}
	build(x*2,h,mid); build(x*2+1,mid+1,t);
	updata(x);
}
void down(int x)
{
	if(p[x].max1<=p[x].lazy) p[x].lazy=2000000000;
	if(p[x].lazy==2000000000) return;
	if(p[x].h!=p[x].t)
	{
		if(p[x].lazy<p[x*2].lazy) p[x*2].lazy=p[x].lazy;
		if(p[x].lazy<p[x*2+1].lazy) p[x*2+1].lazy=p[x].lazy;		
	} 
	if(p[x].max1>p[x].lazy&&p[x].max2<p[x].lazy)
	{
		p[x].sum=p[x].sum-(p[x].max1-p[x].lazy)*p[x].num;
		p[x].max1=p[x].lazy;
	} else
	{
		down(x*2); down(x*2+1);
		updata(x);
	}
	p[x].lazy=2000000000;
}
void change(int x,int h,int t,int w)
{
	down(x);
	if(p[x].h>t||p[x].t<h) return;
	if(h<=p[x].h&&p[x].t<=t)
	{
		p[x].lazy=min(p[x].lazy,w); down(x); return;
	}
	change(x*2,h,t,w); change(x*2+1,h,t,w);
	updata(x);
}
int query2(int x,int h,int t)
{
	down(x);
	if(p[x].h>t||p[x].t<h) return(0);
	if(h<=p[x].h&&p[x].t<=t) return(p[x].sum);
	return(query2(x*2,h,t)+query2(x*2+1,h,t));
}//change(1,l,r,w),query2(1,l,r)
int a[500005],qzh[500005],hzh[500005],ANS[500005];
signed main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> b[i];
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		change(1,1,i,b[i]);
		qzh[i]=query2(1,1,i);
	}
	for(int i=1;i<=n*4;i++)
		p[i]={0,0,0,0,0,0,0};
	build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		change(1,i,n,b[i]);
		hzh[i]=query2(1,i,n);
	}
	int ans=0,w=0;
	for(int i=1;i<=n;i++)
	{
		if(qzh[i]+hzh[i+1]>ans)
			ans=qzh[i]+hzh[i+1],w=i;
	}
	int now=2e9;
	for(int j=w;j>0;j--)
	{
		now=min(now,b[j]);
		ANS[j]=now;
	}
	now=2e9;
	for(int i=w+1;i<=n;i++)
	{
		now=min(now,b[i]);
		ANS[i]=now;
	}
	for(int i=1;i<=n;i++)
		cout << ANS[i] << " ";
	return 0;
}