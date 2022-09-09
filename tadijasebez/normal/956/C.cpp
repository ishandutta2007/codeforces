#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=100050;
int a[N],b[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	b[n]=a[n]+1;
	for(i=n-1;i;i--)
	{
		b[i]=max(b[i+1]-1,a[i]+1);
	}
	for(i=2;i<=n;i++) b[i]=max(b[i],b[i-1]);
	//for(i=1;i<=n;i++) printf("%i ",b[i]);printf("\n");
	ll sol=0;
	int was=0;
	for(i=1;i<=n;i++)
	{
		sol+=b[i]-a[i]-1;
	}
	printf("%lld\n",sol);
	return 0;
}