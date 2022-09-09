#include <stdio.h>
#define ll long long
const int N=5050;
ll min(ll a, ll b){ return a>b?b:a;}
int a[N];
ll Solve(int l, int r, int last)
{
	if(l>r) return 0;
	int i,taj=0;
	for(i=l;i<=r;i++) if(!taj || a[taj]>a[i]) taj=i;
	return min(r-l+1,Solve(l,taj-1,a[taj])+Solve(taj+1,r,a[taj])+a[taj]-last);
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	printf("%lld\n",Solve(1,n,0));
	return 0;
}