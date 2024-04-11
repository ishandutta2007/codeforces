#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long



int main()
{
	//ios_base::sync_with_stdio(0);
	int n, k;
	scanf("%d%d", &n, &k);
	if(n/2>k)
	{
		printf("-1\n");
		return 0;
	}
	if(n==1)
	{
		if(k==0) printf("1\n");
		else printf("-1\n");
		return 0;
	}
	int x=(n-2)/2;
	printf("%d %d ", k-x, 2*(k-x));
	for(int i=2; i<n; i++) printf("%d ", 2*(k-x)+i);
	printf("\n");
	return 0;
}