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
#define pb pop_back
const LL mod=1000000009;
const LL p=10007;

int n;
LL T[2][1000006], P[1000006];
char C[2][1000006];

int main()
{
	P[0]=1;
	for(int i=1; i<1000006; i++)
		P[i]=(P[i-1]*p)%mod;
	//ios_base::sync_with_stdio(0);
	scanf("%d%s%s", &n, C[0], C[1]);
	n--;
	for(int i=0; i<n; i++)
	{
		if(C[1][i]=='N')
		{
			C[1][i]='S';
			continue;
		}
		if(C[1][i]=='S')
		{
			C[1][i]='N';
			continue;
		}
		if(C[1][i]=='E')
		{
			C[1][i]='W';
			continue;
		}
		if(C[1][i]=='W')
		{
			C[1][i]='E';
			continue;
		}
	}
	LL h=0;
	for(int i=n-1; i>=0; i--)
	{
		h=(h*p+(int)C[0][i])%mod;
		T[0][i]=h;
	}
	h=0;
	for(int i=0; i<n; i++)
	{
		h=(h*p+(int)C[1][i])%mod;
		T[1][i]=h;
	}
	for(int i=0; i<n; i++)
	{
		LL x=T[1][n-1];
		if(i>0)
			x-=(T[1][i-1]*P[n-i])%mod;
		if(x<0)
			x+=mod;
		if(T[0][i]==x)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}