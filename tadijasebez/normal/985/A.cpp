#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=105;
int a[N];
int pos(int x, int y){ x-=y;if(x<0) return -x;return x;}
int main()
{
	int n,i;
	scanf("%i",&n);n/=2;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	int sol=1e9;
	int ans=0;
	for(i=1;i<=n;i++) ans+=pos(i*2-1,a[i]);
	sol=min(sol,ans);
	ans=0;
	for(i=1;i<=n;i++) ans+=pos(i*2,a[i]);
	sol=min(sol,ans);
	printf("%i\n",sol);
	return 0;
}