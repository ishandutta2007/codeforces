#include<bits/stdc++.h>
using namespace std;
int n,m;
bool ap[3000000];
long long T;
long long p;
long long s;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0) {
		x=1;
		y=0;
		return a;
	}
	long long d=exgcd(b,a%b,x,y);
	long long z=x;
	x=y;
	y=z-y*(a/b);
	return d;
}
long long inverse(long long l)
{
	l=l%1000000007l+1000000007l;
	long long x,y;
	exgcd(l,1000000007l,x,y);
	return (x%1000000007l+1000000007l)%1000000007l;
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	for(int jj=1;jj<=t;jj++)
	{
		int rb,cb,rd,cd;
		s=0;
		scanf("%d%d%d%d%d%d%lld",&n,&m,&rb,&cb,&rd,&cd,&p);
		T=2*(n-1)*(m-1);
		int dr=1,dc=1;
		for(int i=0;i<T;i++)
		{
			if((rb==rd)||(cb==cd))
			{
				s++;
				ap[i]=true;
			} 
			else ap[i]=false;
			rb+=dr;
			cb+=dc;
			if(rb==n+1)
			{
				dr=-dr;
				rb-=2;
			}
			if(rb==0)
			{
				dr=-dr;
				rb+=2;
			 } 
			if(cb==m+1)
			{
				dc=-dc;
				cb-=2;
			}
			if(cb==0)
			{
				dc=-dc;
				cb+=2;
			}
		}
		p=(p*inverse(100))%1000000007l;
		long long w=1;
		for(int x=1;x<=s;x++)
		{
			w*=1-p;
			w%=1000000007l;
		}
		long long w1=inverse(1-w);
		long long w2=(w*((w1*w1)%1000000007))%1000000007;
		long long ans=0;
		long long pp=p,kk=0;
		for(int i=0;i<T;i++)
		{
			if(!ap[i]) continue;
			long long oi=(pp*((i*w1+T*w2)%1000000007l))%1000000007l;
			ans+=oi;
			ans%=1000000007l;
		    pp*=1-p;
		    pp%=1000000007l;
		} 
		printf("%lld\n",(ans%1000000007l+1000000007l)%1000000007l);
	}
	return 0;
}