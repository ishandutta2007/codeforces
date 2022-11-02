#include<cstdio>
#include<algorithm>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int a;
			scanf("%d", &a);
		}
	}
	printf("%d\n", (m*(m-1))/2);
	if(k==0)
	{
		
		for(int i=1; i<m; i++)
		{
			for(int j=i+1; j<=m; j++)
			{
				printf("%d %d\n", i, j);
			}
		}
	}
	else
	{
		for(int i=m; i>1; i--)
		{
			for(int j=i-1; j>0; j--)
			{
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}