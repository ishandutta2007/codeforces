#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

vector<pair<int, int> > A, B;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{
			if(i*i+j*j==a*a) A.PB(MP(-1*i, j));
			
		}
	}
	for(int i=1; i<=b; i++)
	{
		for(int j=1; j<=b; j++)
		{
			if(i*i+j*j==b*b) B.PB(MP(i, j));
		}
	}
	for(int i=0; i<A.size(); i++)
	{
		for(int j=0; j<B.size(); j++)
		{
			if(A[i].F*B[j].F+A[i].S*B[j].S==0 && A[i].S!=B[j].S)
			{
				printf("YES\n");
				printf("0 0\n%d %d\n%d %d\n", A[i].F, A[i].S, B[j].F, B[j].S);
				return 0;
			}
			if(A[i].F*B[j].S+A[i].S*B[j].F==0 && A[i].S!=B[j].F)
			{
				printf("YES\n");
				printf("0 0\n%d %d\n%d %d\n", A[i].F, A[i].S, B[j].S, B[j].F);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}