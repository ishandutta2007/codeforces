#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
long long a[N],b[N];
int main()
{
	int n,i,q,l,r,t;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
		a[i]+=a[i-1];
	}
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++) b[i]+=b[i-1];
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		printf("%lld\n",t==1?a[r]-a[l-1]:b[r]-b[l-1]);
	}
	return 0;
}