#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200050;
#define ll long long
int t[N],d[N],id[N];
ll a[N];
bool comp(int i, int j){ return (t[i]==t[j] && d[i]<d[j]) || t[i]>t[j];}
int main()
{
	int n,i;ll x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		x=a[i];
		while(x%3==0) x/=3,t[i]++;
		while(x%2==0) x/=2,d[i]++;
		id[i]=i;
	}
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n;i++) printf("%lld ",a[id[i]]);
	printf("\n");
	return 0;
}