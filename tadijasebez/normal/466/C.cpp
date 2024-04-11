#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=500050;
int a[N];
long long b[N];
vector<int> v;
long long g1,g2,sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),b[i]=b[i-1]+a[i];
	if(b[n]%3==0)
	{
		g1=b[n]/3;
		g2=g1*2;
	}
	else
	{
		printf("0\n");
		return 0;
	}
	for(i=2;i<n;i++) if(b[i]==g2) v.push_back(i);
	for(i=1;i<n;i++)
	{
		if(b[i]==g1)
		{
			int res=v.end()-upper_bound(v.begin(),v.end(),i);
			sol+=res;
		}
	}
	printf("%lld\n",sol);
	return 0;
}