#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,a[N],s[N];
long long sol(int x)
{
	for(int i=0;i<=n+n;i++)
		s[i]=0;
	int c=n,p=0;
	long long t=0;
	for(int i=1;i<=n;i++)
	{
		s[c]++;
		if(a[i]>=x)
			p+=s[c],c++;
		else
			c--,p-=s[c];
		t+=p;
	}
	return t;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%lld\n",sol(m)-sol(m+1));
	return 0;
}