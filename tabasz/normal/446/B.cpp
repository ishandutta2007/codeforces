#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<iostream>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

priority_queue<LL> Q1, Q2;
int T1[1001], T2[1001];
LL res=-1000000000000000000LL, A[1000001], B[1000001];

int main()
{
	int n, m, k, p;
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int a;
			scanf("%d", &a);
			T1[i]+=a;
			T2[j]+=a;
		}
	}
	for(int i=0; i<n; i++) Q1.push((LL)T1[i]);
	for(int i=0; i<m; i++) Q2.push((LL)T2[i]);
	for(int i=1; i<=k; i++)
	{
		A[i]=A[i-1]+Q1.top();
		LL x=Q1.top();
		Q1.pop();
		x-=(LL)m*(LL)p;
		Q1.push(x);
		//printf("A[%d]=%lld\n", i, A[i]);
	}
	for(int i=1; i<=k; i++)
	{
		B[i]=B[i-1]+Q2.top();
		LL x=Q2.top();
		Q2.pop();
		x-=(LL)n*(LL)p;
		Q2.push(x);
		//printf("B[%d]=%lld\n", i, B[i]);
	}
	for(int i=0; i<=k; i++) res=max(res, A[i]+B[k-i]-(LL)i*(LL)(k-i)*(LL)p);
	cout<< res << '\n';
	return 0;
}