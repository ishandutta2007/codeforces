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

int T[55][55], n, A[55];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", T[i]+j);
	if(n==2)
	{
		printf("1 2\n");
		return 0;
	}
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int maxi=0;
			for(int k=1; k<=n; k++)
				maxi=max(maxi, T[j][k]);
			if(maxi==i)
			{
				A[j]=i;
				break;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(A[i]>0)
			printf("%d ", A[i]);
		else
			printf("%d ", n);
	}
	printf("\n");
	return 0;
}