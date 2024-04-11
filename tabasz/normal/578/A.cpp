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

int main()
{
	//ios_base::sync_with_stdio(0);
	int a, b;
	scanf("%d%d", &a, &b);
	if(a<b)
	{
		printf("-1\n");
		return 0;
	}
	double x=((double)(a+b)/(double)b)/2;
	x=floor(x);
	printf("%.9lf\n", (double)(a+b)/(x*2));
	return 0;
}