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

LL P[64], a, b, res;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%lld%lld", &a, &b);
	P[0]=1;
	for(int i=1; i<64; i++)
		P[i]=P[i-1]*2;
	for(int i=2; i<63; i++)
	{
		LL x=P[i]-1;
		for(int j=0; j+1<i; j++)
		{
			LL y=x-P[j];
			if(a<=y && b>=y)
				res++;
		}
	}
	printf("%lld\n", res);
	return 0;
}