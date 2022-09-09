#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=200050;
int a[N],sum;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=n;i++)
	{
		if(a[i]>=(a[n]+1)/2)
		{
			printf("%i\n",i);
			return 0;
		}
	}
	return 0;
}