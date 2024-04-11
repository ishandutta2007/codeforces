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

bool B[1005];
vector<int> V;

int main()
{
	//ios_base::sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	for(int i=2; i<=n; i++)
	{
		if(B[i])
			continue;
		int x=i;
		while(x<=n)
		{
			V.PB(x);
			x*=i;
		}
		x=i;
		while(x<=n)
		{
			B[x]=1;
			x+=i;
		}
	}
	printf("%d\n", (int)V.size());
	for(int i=0; i<(int)V.size(); i++)
		printf("%d ", V[i]);
	printf("\n");
	return 0;
}