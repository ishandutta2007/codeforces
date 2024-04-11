#include<iostream>
#include<string.h>
#include<stdio.h>
#define la (2*N+1)
#define ra (2*N+3)
using namespace std;
double s[600000];
double lm[600000];
double rm[600000];
double mx[600000];
int a[600000];
double p[600000];
double ans;
int i,n,m,N,x,y,c;
void mg(int z,int x,int y)
{
	mx[z]=max(max(mx[x],mx[y]),rm[x]+lm[y]);
	lm[z]=max(lm[x],s[x]+lm[y]);
	rm[z]=max(rm[y],s[y]+rm[x]);
	s[z]=s[x]+s[y];
}
void clr(int x)
{
	lm[x]=rm[x]=mx[x]=s[x]=0;
}
double qy(int l,int r)
{
	clr(0);
	clr(la);
	clr(ra);
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)
			mg(la,la,l^1);
		if(r&1)
			mg(ra,r^1,ra);
	}
	mg(0,la,ra);
	return mx[0];
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	for(N=n;N!=(N&-N);N+=N&-N);
	for(i=N+1;i<=N+n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=N+1;i<N+n;i++)
	{
		scanf("%lf",&p[i]);
		p[i]*=0.01;
		lm[i]=rm[i]=mx[i]=max(s[i]=(a[i+1]-a[i])*0.5-c*p[i],.0);
	}
	for(i=N-1;i>0;i--)
		mg(i,i*2,i*2+1);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		y--;
		ans+=qy(x,y);
	}
	printf("%.10lf",ans);
	return 0;
}