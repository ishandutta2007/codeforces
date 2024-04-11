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
	int n;
	scanf("%d", &n);
	int x=(n*n)/2;
	if(n%2==1) x++;
	printf("%d\n", x);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if((i+j)%2==0) printf("C");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}