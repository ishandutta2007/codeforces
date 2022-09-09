#include <stdio.h>
#include <map>
using namespace std;
map<long long,int> cnt;
long long sol,x;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&x);
		for(j=1;j<32;j++)sol+=cnt[(1ll<<j)-x];
		cnt[x]++;
	}
	printf("%lld\n",sol);
	return 0;
}