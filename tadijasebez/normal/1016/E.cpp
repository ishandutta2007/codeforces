#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
#define db double
const int N=200050;
db sum[N];
int main()
{
	vector<db> all;
	int sy,a,b,n,q,i,x,y;
	scanf("%i %i %i",&sy,&a,&b);
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		int l,r;
		scanf("%i %i",&l,&r);
		sum[i]=sum[i-1]+r-l;
		all.pb(l);
		all.pb(r);
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&x,&y);
		db sol=0;
		db l=(db)a-(db)sy/(y-sy)*(x-a);
		db r=(db)b-(db)sy/(y-sy)*(x-b);
		int L=lower_bound(all.begin(),all.end(),l)-all.begin();
		int R=lower_bound(all.begin(),all.end(),r)-all.begin();
		sol+=sum[R/2]-sum[L/2];
		if(L&1) sol-=l-all[L-1];
		if(R&1) sol+=r-all[R-1];
		sol=sol/y*(y-sy);
		printf("%llf\n",sol);
	}
	return 0;
}