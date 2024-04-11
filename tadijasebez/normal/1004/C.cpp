#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
map<int,bool> was;
const int N=100050;
int a[N],b[N];
int main()
{
    int n,i;
    scanf("%i",&n);
    for(i=1;i<=n;i++) scanf("%i",&a[i]);
    for(i=n;i>=1;i--)
	{
		b[i]=b[i+1];
		if(!was[a[i]]) b[i]++;
		was[a[i]]=1;
	}
	was.clear();
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		if(!was[a[i]]) sol+=b[i+1];
		was[a[i]]=1;
	}
	printf("%lld\n",sol);
    return 0;
}