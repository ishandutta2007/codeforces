#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int cal(int x,int y)
{
	if(x==1)
		return y;
	int t=y/x;
	return t+cal(y%x,x);
}
int mik(int x,int y)
{
	if(x==1)
		return y-2;
	int t=y/x-1;
	return t+mik(y%x,x);
}
int n,r,ans,z;
char c[1000020],*s=c+1000000;
int mk(int x,int y)
{
	while(x!=1||y!=1)
	{
		if(x>=y)
			x-=y,*--s='T';
		else
			y-=x,*--s='B';
	}
	if(*s=='T')
	{
		for(char *i=s;i<c+1000000;i++)
		{
			if(*i=='B')
				*i='T';
			else
				*i='B';
		}
	}
	*--s='T';
	puts(s);
}
int main()
{
	scanf("%d %d",&n,&r);
	if(n==1&&r==1)
	{
		puts("0");
		puts("T");
		return 0;
	}
	ans=0x3f3f3f3f;
	for(int i=1;i<=r;i++)
		if(gcd(i,r)==1)
		{
			if(i==7)
				i=7;
			if(cal(i,r)==n)
			{
				int cnt=mik(i,r);
				if(cnt<ans)
				{
					z=i;
					ans=cnt;
				}
			}
			
		}
	if(ans==0x3f3f3f3f)
		puts("IMPOSSIBLE");
	else
	{
		printf("%d\n",ans);
		mk(z,r);
	}
	return 0;
}