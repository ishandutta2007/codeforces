#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int N=200050;
map<ll,int> l,r;
ll sol;
int k;
void Get(int x)
{
	int i,j;
	if(x%k==0)
	{
		i=x/k;
		j=k;
		sol+=(ll)l[i]*r[(ll)i*j*j];
	}
}
int x[N];
int main()
{
	int n,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&x[i]),r[x[i]]++;
	for(i=1;i<=n;i++)
	{
		r[x[i]]--;
		Get(x[i]);
		l[x[i]]++;
	}
	printf("%lld\n",sol);
	return 0;
}