#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
int a[N],sol;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sol=n-1;
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		int j=upper_bound(a+1,a+1+n,a[i]*2)-a;
		sol=min(sol,i-1+n-j+1);
	}
	printf("%i\n",sol);
	return 0;
}