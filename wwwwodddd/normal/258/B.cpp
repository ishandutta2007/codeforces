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
typedef long long ll;
int n,ct;
int c[100];
long long t[15];
int C(int x,int y)
{
	long long _=1;
	for(int i=0;i<y;i++)
		_=_*(x-i)/(i+1);
	return _;
}
int p=1000000007;
long long pww(long long x,long long y)
{
	long long _=1;
	for(;y;y>>=1)
	{
		if(y&1)
			_=_*x%p;
		x=x*x%p;
	}
	return _;
}
int pw(int x,int y)
{
	long long _=1;
	for(int i=0;i<y;i++)
		_*=x;
	return _;
}
ll CC(ll x,ll y)
{
	ll _=1;
	for(int i=0;i<y;i++)
		_=_*(x-i)%p*pww(i+1,p-2)%p;
	return _;
}
long long f[120][8];
int main()
{
	scanf("%d",&n),n++;
	for(int i=t[0]=1;i<15;i++)
		t[i]=t[i-1]*10;
	for(int i=11;i--;)
	{
		int u=n/t[i]%10;
		for(int j=0;j<u;j++)
		{
			int yy=ct;
			if(j==4||j==7)
				yy++;
			for(int k=0;k<=i;k++)
			{
				c[k+yy]+=pw(8,i-k)*pw(2,k)*C(i,k);
			}
		}
		if(u==4||u==7)
			ct++;
	}
	c[0]--;
//	for(int i=0;i<11;i++)
//		cout << c[i] << endl;
	f[0][0]=1;
	for(int i=0;i<11;i++)
	{
		for(int j=80;j>=0;j--)
			for(int k=5;k>=0;k--)
				if(f[j][k])
			{
				for(int l=1;l+k<=6;l++)
					f[j+i*l][k+l]=(f[j+i*l][k+l]+f[j][k]*CC(c[i],l)%p)%p;
			}
	}
	long long z=0;
	long long s=0;
	for(int i=20;i>=0;i--)
	{
		z=(z+f[i][6]*s)%p;
		s+=c[i];
	}
	for(int i=1;i<7;i++)
		z=z*i%p;
	cout << z << endl;
	return 0;
}