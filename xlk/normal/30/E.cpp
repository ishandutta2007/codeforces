#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,p=1234567891,f[100020];
long long h[100020],g[100020],pw[100020];
char s[100020];
long long L_R(int L,int R)
{
	return h[R+1]-h[L]*pw[R-L+1];
}
long long R_L(int L,int R)
{
	return g[L]-g[R+1]*pw[R-L+1];
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
		h[i+1]=h[i]*p+s[i];
	for(int i=n;i--;)
		g[i]=g[i+1]*p+s[i];
	for(int i=pw[0]=1;i<=n;i++)
		pw[i]=pw[i-1]*p;
	for(int i=0;i<=n;i++)
		f[i]=0x3f3f3f3f;
	for(int i=0;i<n;i++)
	{
		int l=0,r=(n-i)/2;
		while(l<r)
		{
			int m=(l+r+1)/2;
			if(L_R(i,i+m-1)==R_L(n-m,n-1))
				l=m;
			else
				r=m-1;
		}
		f[l]=min(f[l],i-1);
	}
	for(int i=n;i;i--)
		f[i-1]=min(f[i-1],f[i]),f[i]+=i;
	int z=0,p0,l0,p1,l1,p2,l2;
	for(int i=0;i<n;i++)
	{
		int l=0,r=min(i,n-1-i);
		while(l<r)
		{
			int m=(l+r+1)/2;
			if(L_R(i-m,i)==R_L(i,i+m))
				l=m;
			else
				r=m-1;
		}
		int len=l;l=0;r=n-(i+len)-1;
		while(l<r)
		{
			int m=(l+r+1)/2;
			if(f[m]<i-len)
				l=m;
			else
				r=m-1;
		}
		if(len*2+1+l*2>z)
		{
			z=len*2+1+l*2;
			p0=f[l]-l+2;
			l0=l;
			p1=i-len+1;
			l1=len*2+1;
			p2=n-l+1;
			l2=l;
		}
	}
	if(l0)
		printf("3\n%d %d\n%d %d\n%d %d\n",p0,l0,p1,l1,p2,l2);
	else
		printf("1\n%d %d\n",p1,l1);
	return 0;
}