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

int n, T[500005];
LL r, res;
char C[500005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", T+i);
	scanf("%s", C);
	for(int i=0; i<n; i++)
	{
		if(C[i]=='B')
			r+=T[i];
	}
	res=r;
	//printf("%d\n", res);
	LL tmp=0;
	for(int i=0; i<n; i++)
	{
		if(C[i]=='A')
			tmp+=T[i];
		else
			tmp-=T[i];
		res=max(res, r+tmp);
	}
	tmp=0;
	for(int i=n-1; i>=0; i--)
	{
		if(C[i]=='A')
			tmp+=T[i];
		else
			tmp-=T[i];
		//if(i==4)
		//	printf("%d %d\n", r, tmp);
		res=max(res, r+tmp);
	}
	printf("%lld\n", res);
	return 0;
}