#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll sol;
priority_queue<int> pq;
const int N=100050;
int a[N],b[N];
int main()
{
	int n,i,k1,k2,k;
	scanf("%i %i %i",&n,&k1,&k2);k=k1+k2;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	for(i=1;i<=n;i++)
	{
		pq.push(max(a[i],b[i])-min(a[i],b[i]));
	}
	while(k-- && pq.size())
	{
		int x=pq.top();
		pq.pop();
		if(x)
		{
			x--;
			pq.push(x);
		}
		else
		{
			pq.push(1);
		}
	}
	while(pq.size())
	{
		int x=pq.top();
		pq.pop();
		sol+=(ll)x*x;
	}
	printf("%lld\n",sol);
	return 0;
}