#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100050;
int a[N];
double sol;
double max(double a, double b){ return a>b?a:b;}
int main()
{
	int n,i,u;
	scanf("%i %i",&n,&u);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	bool was=0;
	for(i=1;i<=n-2;i++)
	{
		int top=n,bot=i+2,mid,ans=-1;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(a[mid]-a[i]<=u) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		if(ans!=-1)
		{
			was=1;
			sol=max(sol,(double)(a[ans]-a[i+1])/(a[ans]-a[i]));
		}
	}
	if(was) printf("%.12llf\n",sol);
	else printf("-1\n");
	return 0;
}