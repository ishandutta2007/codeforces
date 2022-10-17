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
int n,q,x;
ll a[100020];
ll z[100020];
ll s[100020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%I64d",a+i);
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=1;i<n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i*i<=n;i++)
	{
		int c=0,t=0,w=1;
		for(int j=0;j<n;j++)
		{
			z[i]+=a[j]*t;
			c++;
			if(c==w)
			{
				c=0;
				w*=i;
				t++;
			}
		}
	}
	for(scanf("%d",&q);q--;)
	{
		scanf("%d",&x);
		if(x>=n)
			x=n-1;
		if((long long)x*x<=n)
			printf("%I64d ",z[x]);
		else
			printf("%I64d ",2*s[n-1]-s[x]);
	}
	return 0;
}