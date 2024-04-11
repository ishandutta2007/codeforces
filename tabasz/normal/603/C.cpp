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

int n, k, res;
int T[]={0, 1, 0, 1, 2, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0};

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	if(k%2==0)
	{
		for(int i=0; i<n; i++)
		{
			int a;
			scanf("%d", &a);
			if(a<3)
				res^=a;
			else
				res^=(1-a%2);
		}
		if(res!=0)
			printf("Kevin\n");
		else
			printf("Nicky\n");
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			int a;
			scanf("%d", &a);
			if(a<16)
				res^=T[a];
			else if(a%2==0)
			{
				int tmp=0;
				while(a%2==0)
				{
					a/=2;
					tmp++;
				}
				if(tmp%2==0)
				{
					if(a==3)
						res^=1;
					else
						res^=2;
				}
				else
				{
					if(a==3)
						res^=2;
					else
						res^=1;
				}
			}
			
		}
		if(res!=0)
			printf("Kevin\n");
		else
			printf("Nicky\n");
	}
	return 0;
}