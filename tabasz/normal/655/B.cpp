#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, k;
LL res;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	k=min(k, n/2);
	for(int i=1; i<=k; i++)
		res+=i-1;
	for(int i=k+1; i+k<=n; i++)
		res+=k;
	for(int i=n-k+1; i<=n; i++)
		res+=i-1;
	printf("%lld\n", res);
	return 0;
}