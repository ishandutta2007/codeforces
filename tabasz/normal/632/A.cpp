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

int n, p;
char C[45][40];
LL res=0, tmp=0;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &p);
	for(int i=0; i<n; i++)
		scanf("%s", C[i]);
	for(int i=n-1; i>=0; i--)
	{
		if(C[i][4]=='p')
		{
			res+=(LL)((p*(2*tmp+1))/2);
			tmp*=2;
			tmp++;
		}
		else
		{
			res+=tmp*p;
			tmp*=2;
		}
	}
	printf("%lld\n", res);
	return 0;
}