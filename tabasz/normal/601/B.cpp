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
const int M=1024*128;

int n, m;
PII T[20][100005];
int P[20], L[100005];

LL go(int p, int k)
{
	if(p>k)
		return 0;
	int len=k-p+1;
	PII m=max(T[L[len]][p], T[L[len]][k-P[L[len]]+1]);
	return (LL)(m.S-p+1)*(LL)(k-m.S+1)*(LL)m.F+go(p, m.S-1)+go(m.S+1, k);
}

int main()
{
	P[0]=1;
	for(int i=1; i<20; i++)
		P[i]=P[i-1]*2;
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	int len=0;
	for(int i=1; i<=n; i++)
	{
		while(P[len+1]<=i)
			len++;
		L[i]=len;
	}
	int prev;
	scanf("%d", &prev);
	for(int i=1; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		int x=abs(a-prev);
		T[0][i]=MP(x, i);
		prev=a;
	}
	for(int i=1; i<18; i++)
		for(int j=1; j<n; j++)
			T[i][j]=max(T[i-1][j], T[i-1][min(j+P[i-1], n-1)]);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		b--;
		printf("%lld\n", go(a, b));
	}
	return 0;
}