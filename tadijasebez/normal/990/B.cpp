#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
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
multiset<int> ord;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		while(ord.size() && *ord.rbegin()<a[i] && *ord.rbegin()+k>=a[i])
		{
			ord.erase(--ord.end());
		}
		ord.insert(a[i]);
	}
	printf("%i\n",ord.size());
	return 0;
}