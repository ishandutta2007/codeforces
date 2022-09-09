#include <stdio.h>
#define ll long long
const int N=1000050;
char s[N];
int a[N],sz;
ll sol[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) if(s[i]=='D') a[++sz]=i;
	ll sum=0;
	for(i=1;i<=sz;i++)
	{
		sum+=(a[i]-i)*2;
		sol[i]=sum+i;
	}
	sz=0;
	for(i=n;i>=1;i--) if(s[i]=='U') a[++sz]=i;
	sum=0;
	for(i=1;i<=sz;i++)
	{
		int j=n-i+1;
		sum+=(j-a[i])*2;
		sol[j]=sum+i;
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	return 0;
}