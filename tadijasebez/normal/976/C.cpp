#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
bool ckmax(int &a, int b){ int c=a;a=max(a,b);return c!=a;}
bool ckmin(int &a, int b){ int c=a;a=min(a,b);return c!=a;}
bool ckmax(ll &a, ll b){ ll c=a;a=max(a,b);return c!=a;}
bool ckmin(ll &a, ll b){ ll c=a;a=min(a,b);return c!=a;}
const int N=300050;
int l[N],r[N],id[N];
bool comp(int i, int j){ return (l[i]==l[j] && r[i]<r[j]) || l[i]>l[j];}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&l[i],&r[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	int Min=0;
	for(i=1;i<=n;i++)
	{
		if(Min && r[Min]<=r[id[i]])
		{
			printf("%i %i\n",Min,id[i]);
			return 0;
		}
		if(!Min || r[Min]>r[id[i]])
		{
			Min=id[i];
		}
	}
	printf("-1 -1\n");
	return 0;
}