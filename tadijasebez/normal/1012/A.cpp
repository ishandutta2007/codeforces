#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
map<int,int> cnt;
const int N=200050;
int a[N];
int main()
{
	int n,i,Max=0;
	scanf("%i",&n);n*=2;
	for(i=1;i<=n;i++) scanf("%i",&a[i]),cnt[a[i]]++,Max=max(Max,cnt[a[i]]);
	sort(a+1,a+1+n);
	if(Max>=n/2) printf("0\n");
	else
	{
		ll sol=(ll)(a[n/2]-a[1])*(a[n]-a[n/2+1]);
		for(i=2;i<=n/2;i++)
		{
			sol=min(sol,(ll)(a[n]-a[1])*(a[i+n/2-1]-a[i]));
			//printf("%i %i\n",i+n/2-1,i);
		}
		//printf("%i %i %i %i\n",a[1],a[n/2],a[n/2+1],a[n]);
		printf("%lld\n",sol);
	}
    return 0;
}