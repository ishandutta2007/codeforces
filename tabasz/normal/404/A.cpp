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
	int n;
	char c1, c2, c;
	scanf("%d%c", &n, &c);
	scanf("%c%c", &c1, &c2);
	if(c1==c2)
	{
		printf("NO\n");
		return 0;
	}
	for(int i=3; i<n; i++)
	{
		scanf("%c", &c);
		if(c!=c2)
		{
			printf("NO\n");
			return 0;
		}
	}
	scanf("%c", &c);
	if(c!=c1)
	{
		printf("NO\n");
		return 0;
	}
	scanf("%c", &c);
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%c", &c);
			if((i==j || i+j==n+1) && c!=c1)
			{
				printf("NO\n");
				return 0;
			}
			if(i!=j && i+j!=n+1 && c!=c2)
			{
				printf("NO\n");
				return 0;
			}
		}
		scanf("%c", &c);
	}
	printf("YES\n");
	return 0;
}