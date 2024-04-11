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

int n, a, b;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &a, &b);
	if(n>a*b)
	{
		printf("-1\n");
		return 0;
	}
	int tmp1=1, tmp2=2;
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=b; j++)
		{
			if((i+j)%2==0)
			{
				if(tmp1>n)
					printf("0 ");
				else
					printf("%d ", tmp1);
				tmp1+=2;
			}
			else
			{
				if(tmp2>n)
					printf("0 ");
				else
					printf("%d ", tmp2);
				tmp2+=2;
			}
		}
		printf("\n");
	}
	return 0;
}