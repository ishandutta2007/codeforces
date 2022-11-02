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

int n, m, res, lcm;
int T[1000005], A[1000005], B[1000005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		scanf("%d", T+i);
		if(T[i]<=m)
			A[T[i]]++;
	}
	for(int i=1; i<=m; i++)
	{
		if(A[i]==0)
			continue;
		for(int j=i; j<=m; j+=i)
			B[j]+=A[i];
	}
	for(int i=1; i<=m; i++)
	{
		if(B[i]>res)
		{
			res=B[i];
			lcm=i;
		}
	}
	if(res==0)
	{
		printf("1 0\n");
		return 0;
	}
	printf("%d %d\n", lcm, res);
	for(int i=0; i<n; i++)
		if(lcm%T[i]==0)
			printf("%d ", i+1);
	printf("\n");
	return 0;
}