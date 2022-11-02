#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back



int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if(k>=(n*(n-1))/2)
	{
		printf("no solution\n");
		return 0;
	}
	for(int i=0; i<n; i++)
	{
		printf("%d %d\n", i, (i+1)*100000);
	}
	return 0;
}