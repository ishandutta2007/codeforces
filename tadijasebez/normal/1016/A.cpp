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
const int N=200050;
int a[N];
int main()
{
	int n,m,i,st=0;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		int ret=a[i]/m;
		st+=a[i]%m;
		if(st>=m) ret++,st-=m;
		printf("%i ",ret);
	}
	return 0;
}