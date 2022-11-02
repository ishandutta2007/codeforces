#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 
const LL mod=1000000007;

LL res=1;

LL pot(LL a, LL m)
{
	int i=30;
	LL r=1;
	while(i>=0)
	{
		r=(r*r)%mod;
		if((m>>i)%2==1)
			r=(r*a)%mod;
		i--;
	}
	//printf("  %d\n", r);
	return r;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	//scanf("%d", &n);
	cin>> n;
	n++;
	for(int i=n+1; i<=2*n; i++)
		res=(res*i)%mod;
	//printf("%lld\n", res);
	for(int i=1; i<=n; i++)
		res=(res*pot(i, mod-2))%mod;
	res--;
	if(res<0)
		res+=mod;
	//printf("%lld\n", res);
	cout<< res << '\n';
	return 0;
}