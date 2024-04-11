#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
int a[N],b[N];
vector<long long> vals;
long long min(long long a, long long b){ return a>b?b:a;}
long long Solve(long long x)
{
	int top=vals.size()-1;
	int bot=0,mid;
	while(top>bot)
	{
		mid=top+bot>>1;
		if(vals[mid]<x) bot=mid+1;
		else top=mid;
	}
	long long ret;
	if(top>0)
	{
		ret=min(vals[top]-x,x-vals[top-1]);
	}
	else ret=vals[top]-x;
	if(ret<0) ret=-ret;
	return ret;
}
int main()
{
	int n,m,q,i,l,r,v;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=m;i++) scanf("%i",&b[i]);
	long long tmp=0;
	for(i=1;i<=n;i++) tmp+=b[i]*(i&1?-1:1);
	//printf("%i\n",tmp);
	vals.push_back(tmp);
	for(i=n+1;i<=m;i++)
	{
		tmp+=b[i-n];
		tmp=-tmp;
		tmp+=b[i]*(n&1?-1:1);
		vals.push_back(tmp);
		//printf("%i\n",tmp);
	}
	sort(vals.begin(),vals.end());
	long long x=0;
	for(i=1;i<=n;i++) x+=a[i]*(i&1?1:-1);
	//printf("%i\n",x);
	printf("%lld\n",Solve(-x));
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&v);
		if((r-l+1)%2==1)
		{
			x+=v*(l&1?1:-1);
		}
		printf("%lld\n",Solve(-x));
	}
	return 0;
}