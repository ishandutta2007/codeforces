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
ll p=1000000007,z;
ll pw(ll x,ll y)
{
	ll _=1;
	for(;y;y>>=1)
	{
		if(y&1)
			_=_*x%p;
		x=x*x%p;
	}
	return _;
}
int n,a[100020],c[100020];
int b[100020],w;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),c[a[i]]++;
	for(int i=1;i<=100000;i++)
		c[i]+=c[i-1];
	sort(a,a+n);
	for(int i=1;i<=a[n-1];i++)
	{
		w=0;
		for(int j=1;j*j<=i;j++)
			if(i%j==0)
			{
				b[w++]=j;
				if(j*j!=i)
					b[w++]=i/j;
			}
		sort(b,b+w);
		ll u=1;
		for(int i=1;i<w;i++)
		{
			u=u*pw(i,c[b[i]-1]-c[b[i-1]-1])%p;
		}
		z=(z+u*(pw(w,n-c[b[w-1]-1])+p-pw(w-1,n-c[b[w-1]-1]))%p)%p;
	}
	if(z<0)
		z+=p;
	cout << z << endl;
}