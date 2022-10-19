#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,p[N],a[N];
long long s;
int cal(int f)
{
	int x=0,y=n+1;
	for(int g=f;g<=n;g++)
	{
		if(p[g]<x&&p[g]>y)
			return g;
		if(p[g]>y)
			x=p[g];
		else if(p[g]<x)
			y=p[g];
		else if(p[g+1]>p[g])
			x=p[g];
		else
			y=p[g];
	}
	return n+1;
}
void sol(int l,int r)
{
	if(r-l<=1)
		return;
	if(a[l]==a[r])
	{
		for(int i=l;i<=r;i++)
			a[i]=a[l];
		return;
	}
	int md=l+r>>1;
	a[md]=cal(md);
	sol(l,md);
	sol(md,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	a[1]=cal(1);
	a[n]=cal(n);
	sol(1,n);
	for(int i=1;i<=n;i++)
		s+=a[i]-i;
	printf("%lld\n",s);
	return 0;
}