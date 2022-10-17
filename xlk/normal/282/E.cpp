#include<stdio.h>
#include<iostream>
using namespace std;
int t[6000020][2],tt;
void ins(long long x)
{
	int p=0;
	for(int i=40;i--;)
	{
		if(!t[p][x>>i&1])
			t[p][x>>i&1]=++tt;
		p=t[p][x>>i&1];
	}
}
long long qy(long long x)
{
	long long z=0;
	int p=0;
	for(int i=40;i--;)
	{
		if(t[p][~x>>i&1])
			z+=1LL<<i,p=t[p][~x>>i&1];
		else
			p=t[p][x>>i&1];
	}
	return z;
}
int n;
long long a[100020];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%I64d",a+i);
	long long w=0;
	ins(w);
	for(int i=0;i<n;i++)
		ins(w^=a[i]);
	for(int i=0;i<n;i++)
		ans=max(ans,qy(w^=a[i]));
	printf("%I64d",ans);
}