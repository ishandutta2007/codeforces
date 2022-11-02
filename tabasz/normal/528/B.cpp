#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

int n, res;
vector<PII> V;
vector<int> W;
int A[500005];
map<int, int> M;
int dp[500005];

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		W.PB(a+b);
		W.PB(a-b);
		V.PB(MP(a+b, a-b));
	}
	sort(W.begin(), W.end());
	sort(V.begin(), V.end());
	int prev=-1000000001, ind=0;
	for(int i=0; i<(int)W.size(); i++)
	{
		if(W[i]!=prev)
		{
			prev=W[i];
			ind++;
		}
		M[prev]=ind;
	}
	for(int i=0; i<n; i++)
	{
		V[i].F=M[V[i].F];
		V[i].S=M[V[i].S];
		//printf("%d %d\n", V[i].F, V[i].S);
		A[V[i].F]=max(A[V[i].F], V[i].S);
	}
	for(int i=1; i<=2*n; i++)
	{
		if(A[i]>0) dp[i]=max(dp[i-1], dp[A[i]]+1);
		else dp[i]=dp[i-1];
		res=max(res, dp[i]);
	}
	printf("%d\n", res);
	return 0;
}