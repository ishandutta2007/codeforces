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

LL n, a, st=0;
vector<LL> V;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%lld%lld", &n, &a);
	for(int i=0; i<n; i++)
	{
		LL x, y;
		scanf("%lld%lld", &x, &y);
		while((LL)V.size()>st && V[st]<=x)
			st++;
		if((LL)V.size()-st<=a)
		{
			if((LL)V.size()==st)
				V.PB(x+y);
			else
				V.PB(V[V.size()-1]+y);
			printf("%lld ", V[V.size()-1]);
		}
		else
			printf("-1 ");
	}
	printf("\n");
	return 0;
}