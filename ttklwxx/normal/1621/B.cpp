#include<iostream>
#include<cstdio>
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
int l[200005],r[200005],c[200005];
int maxp,minp;
int findc(int x,int y)
{
	if(x==y)return c[x];
	return c[x]+c[y];
}
void check(int x,int y)
{
	if(findc(x,y)<findc(maxp,minp))
	{
		//printf("%d %d %d %d\n",x,y,maxp,minp);
		maxp=x;
		minp=y;
	}
}
int main()
{
	int t,n,k,tmax,tmin;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			l[i]=read();
			r[i]=read();
			c[i]=read();
		}
		maxp=1;
		minp=1;
		tmax=1;
		tmin=1;
		for(int i=1;i<=n;i++)
		{
			if(r[i]>r[maxp])maxp=i,tmax=i;
			if(l[i]<l[minp])minp=i,tmin=i;
			if(r[i]==r[tmax]&&c[i]<c[tmax])tmax=i;
			if(l[i]==l[tmin]&&c[i]<c[tmin])tmin=i;
			if(r[i]==r[maxp]&&l[i]==l[minp])
			{
				check(i,minp);
				check(maxp,i);
				check(i,i);
				check(i,tmin);
				check(tmax,i);
			}
			else if(r[i]==r[maxp])
			{
				check(i,minp);
				check(i,tmin);
			}
			else if(l[i]==l[minp])
			{
				check(maxp,i);
				check(tmax,i);
			}
			check(tmax,minp);
			check(maxp,tmin);
			check(tmax,tmin);
			//printf("%d %d\n",tmax,tmin);
			if(maxp==minp)printf("%d\n",c[maxp]);
			else printf("%d\n",c[maxp]+c[minp]);
		}
	}
	return 0;
}