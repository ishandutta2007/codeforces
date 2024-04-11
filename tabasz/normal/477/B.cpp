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

vector<int> V[100001];
 
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int x=1;
	for(int i=0; i<n; i++)
	{
		if((x+1)%3) V[i].PB(x+1);
		else V[i].PB(x+3);
		for(int j=0; j<3; j++)
		{
			V[i].PB(x);
			x+=2;
		}
	}
	printf("%d\n", (x-2)*k);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<4; j++)
		{
			printf("%d ", V[i][j]*k);
		}
		printf("\n");
	}
	return 0;
}