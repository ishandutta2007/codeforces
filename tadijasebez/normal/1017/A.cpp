#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
const int N=1000050;
int id[N],sum[N];
bool comp(int i, int j){ return sum[i]>sum[j] || (sum[i]==sum[j] && i<j);}
int main()
{
	int n,i,j,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=4;j++) scanf("%i",&x),sum[i]+=x;
		id[i]=i;
	}
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n;i++) if(id[i]==1) printf("%i\n",i);
	//for(i=1;i<=n;i++) printf("%i ",id[i]);
	return 0;
}