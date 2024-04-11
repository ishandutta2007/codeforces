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

LL n, T[2002], dp1[5005], dp2[10005], x, maxi, res;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%lld", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%lld", T+i);
		maxi=max(maxi, T[i]);
	}
	x=n*(n-1)/2;
	sort(T, T+n);
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			dp1[T[j]-T[i]]++;
	for(int i=1; i<=maxi; i++)
		for(int j=1; j<=maxi; j++)
			dp2[i+j]+=dp1[i]*dp1[j];
	LL tmp=0;
	for(int i=1; i<=maxi; i++)
	{
		//printf("%d %lld %lld\n", i, tmp, dp2[i]);
		res+=tmp*dp1[i];
		tmp+=dp2[i];
	}
	//printf("%lld\n", res);
	printf("%.8lf\n", (double)res/(double)(x*x*x));
	return 0;
}