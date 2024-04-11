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
#define pb pop_back

int n, dp[100005], res=1000000, T[100005];
vector<PII> V;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	T[0]=-1000000000;
	for(int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, b));
	}
	sort(V.begin(), V.end());
	for(int i=1; i<=n; i++)
	{
		int a=V[i-1].F, b=V[i-1].S;
		T[i]=a;
		int p=0, k=i-1, mid=(p+k)/2, r=i;
		while(p<=k)
		{
			if(T[mid]>=a-b)
			{
				r=min(r, mid);
				k=mid-1;
			}
			else
				p=mid+1;
			mid=(p+k)/2;
		}
		//printf("%d %d %d\n", i, r, T[r]);
		dp[i]=dp[r-1]+i-r;
		res=min(res, dp[i]+n-i);
	}
	printf("%d\n", res);
	return 0;
}