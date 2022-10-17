#include<stdio.h>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
ll a[10020],l,r,L,R,k,x,y,z;
int c;
using namespace std;
void dfs(ll x)
{
	if(x>1e10)
		return;
	a[c++]=x;
	dfs(x*10+4);
	dfs(x*10+7);
}
ll is(ll l,ll r,ll L,ll R)
{
	return max(min(r,R)-max(l,L)+1,0LL);
}
int main()
{
	dfs(0);
	sort(a,a+c);
	cin>>l>>r>>L>>R>>k;
	for(int i=1,j;i+k<c;i++)
	{
		j=i+k;
		x=is(a[i-1]+1,a[i],l,r);
		y=is(a[j-1],a[j]-1,L,R);
		z+=x*y;
		x=is(a[i-1]+1,a[i],L,R);
		y=is(a[j-1],a[j]-1,l,r);
		z+=x*y;
		if(k==1&&l<=a[i]&&a[i]<=r&&L<=a[i]&&a[i]<=R)
			z--;
	}
	printf("%.15lf",1.*z/(r-l+1)/(R-L+1));
	return 0;
}