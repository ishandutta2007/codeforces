#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=10000;
int a[N];
int main()
{
	int n,i,sum=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	if(2*sum>=9*n) return printf("0\n"),0;
	for(i=1;i<=n;i++)
	{
		sum-=a[i];
		sum+=5;
		if(2*sum>=9*n) return printf("%i\n",i),0;
	}
	return 0;
}