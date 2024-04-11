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

int n, res=0;
int T[100005];
int R[100005];

int dist(PII a, PII b)
{
	return abs(a.F-b.F)+abs(a.S-b.S);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		T[i]=a;
	}
	PII best=MP(0, 0);
	for(int i=1; i<=n; i++)
	{
		if(dist(best, MP(i, 0))>dist(MP(i, T[i]), MP(i, 0)))
			best=MP(i, T[i]);
		R[i]=dist(best, MP(i, 0));
	}
	best=MP(n+1, 0);
	for(int i=n; i>0; i--)
	{
		if(dist(best, MP(i, 0))>dist(MP(i, T[i]), MP(i, 0)))
			best=MP(i, T[i]);
		R[i]=min(R[i], dist(best, MP(i, 0)));
	}
	for(int i=1; i<=n; i++)
		res=max(res, R[i]);
	printf("%d\n", res);
	return 0;
}