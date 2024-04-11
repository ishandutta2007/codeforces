#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=100050;
int a[N];
bool mark[N];
int main()
{
	int n,k,m,l,i,j;
	scanf("%i %i %i",&n,&k,&l);
	m=n*k;
	for(i=1;i<=m;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+m);
	for(i=1;i<=m;i++) if(a[i]-a[1]<=l) j=i;
	int b=0;
	ll sol=0;
	for(i=1;i<=j;i+=k)
	{
		mark[i]=1;
		b++;
		sol+=a[i];
	}
	for(i=j;i>=1;i--)
	{
		if(!mark[i] && b<n)
		{
			b++;
			sol+=a[i];
		}
	}
	if(b<n) printf("0\n");
	else printf("%lld\n",sol);
	return 0;
}