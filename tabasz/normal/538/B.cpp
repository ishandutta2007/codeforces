#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>
int T[10];

int main()
{
	//ios_base:sync_with_stdio(0);
	int a, maxi=0, pot=1;
	scanf("%d", &a);
	for(int i=0; i<8; i++)
	{
		T[i]=(a/pot)%10;
		maxi=max(maxi, T[i]);
		pot*=10;
		if(pot>a) break;
	}
	printf("%d\n", maxi);
	for(int i=0; i<maxi; i++)
	{
		bool b=0;
		for(int j=7; j>=0; j--)
		{
			if(T[j]>0)
			{
				b=1;
				printf("1");
				T[j]--;
			}
			else 
				if(b)
					printf("0");
		}
		printf(" ");
	}
	printf("\n");
	return 0;
}