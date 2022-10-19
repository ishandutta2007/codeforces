#include<iostream>
#include<cstdio>
#include<map> 
#include<cmath>
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
map<int,int>ma;
int n;
bool check(int k)
{
	if(ma[k]!=0)
	{
		if(ma[k]<ma[n])return false;
		else return true;
	}
	printf("? %lld %lld\n",1LL,k);
	fflush(stdout);
	ma[k]=read();
	if(ma[k]<ma[n])return false;
	else return true;
}
signed main()
{
	int t,l,r,mid,ii,jj,kk,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ma.clear();
		printf("? %lld %lld\n",1LL,n);
		fflush(stdout);
		ma[n]=read();
		l=1;
		r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		check(l-1);
		kk=l;
		jj=l-ma[l]+ma[l-1];
		sth=ma[n]-(kk-jj+1)*(kk-jj)/2;
		//printf("%d\n",sth);
		sth=(sqrt(8*sth+1)+1)/2;
		ii=jj-sth;
		printf("! %lld %lld %lld\n",ii,jj,kk);
		fflush(stdout);
	}
	return 0;
}