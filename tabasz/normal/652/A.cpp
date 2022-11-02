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

int a, b, c, d;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int l=b-a;
	if(8*c>=l)
	{
		printf("0\n");
		return 0;
	}
	if(c<=d)
	{
		printf("-1\n");
		return 0;
	}
	l-=8*c;
	int x=(c-d)*12;
	printf("%d\n", (l+x-1)/x);
	return 0;
}