#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll p=1000000007,z;
ll pw(ll x,ll y)
{
	ll _=1;
	for(;y;y>>=1,x=x*x%p)
		if(y&1)
			_=_*x%p;
	return _;
}
int n,x,c[100020];
int b[100020],w;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&x),c[x]++;
	for(int i=1;i<=100000;i++)
		c[i]+=c[i-1];
	for(int i=1;c[i-1]<n;i++)
	{
		w=0;
		for(int j=1;j*j<=i;j++)
			if(i%j==0)
			{
				b[w++]=j-1;
				if(j*j!=i)
					b[w++]=i/j-1;
			}
		sort(b,b+w);
		ll u=1;
		for(int i=1;i<w;i++)
			u=u*pw(i,c[b[i]]-c[b[i-1]])%p;
		z=(z+u*(pw(w,n-c[b[w-1]])+p-pw(w-1,n-c[b[w-1]])))%p;
	}
	printf("%I64d",z);
}