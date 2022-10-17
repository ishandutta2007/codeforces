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
char s[1000020];
long long sb[1000020];
long long sw[1000020];
long long sl[1000020];
long long b[1000020];
long long l[1000020];
long long w[1000020];
long long r[1000020];
long long ans;
int mo=1000000007;
int n,k;
int main()
{
	scanf("%d %d %s",&n,&k,s+1);
	for(int i=1;i<=n;i++)
	{
		sb[i]=sb[i-1]+(s[i]=='B');
		sw[i]=sw[i-1]+(s[i]=='W');
	}
	l[0]=r[n+1]=1;
	for(int i=1;i<=n;i++)
	{
		l[i]=l[i-1];
		if(s[i]=='X')
			l[i]=(l[i]+l[i-1])%mo;
		if(i>=k&&sw[i]-sw[i-k]==0&&s[i-k]!='B')
			b[i]=i-k==0?1:l[i-k-1];
		l[i]=(l[i]-b[i]+mo)%mo;
		sl[i]=(sl[i-1]+b[i])%mo;
		if(s[i]=='X')
			sl[i]=(sl[i]+sl[i-1])%mo;
	}
	for(int i=n;i>0;i--)
	{
		r[i]=r[i+1];
		if(s[i]=='X')
			r[i]=(r[i]+r[i+1])%mo;
		if(i<=n-k+1&&sb[i+k-1]-sb[i-1]==0&&s[i+k]!='W')
			w[i]=i+k==n+1?1:r[i+k+1];
		r[i]=(r[i]-w[i]+mo)%mo;
	}
	for(int i=1;i<=n;i++)
		ans=(ans+sl[i-1]*w[i])%mo;
	printf("%I64d",(ans+mo)%mo);
	return 0;
}