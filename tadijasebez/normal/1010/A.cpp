#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=1050;
int a[N],b[N];
int main()
{
	int i,n,m;
	scanf("%i %i",&n,&m);
	double w=m;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	b[n+1]=b[1];
	for(i=n;i>=1;i--)
	{
		if(b[i+1]-1<=0) return printf("-1\n"),0;
		if(a[i]-1<=0) return printf("-1\n"),0;
		w+=w/(b[i+1]-1);
		//printf("%llf\n",w);
		w+=w/(a[i]-1);
		//printf("%llf\n",w);
	}
	printf("%llf\n",w-m);
	return 0;
}