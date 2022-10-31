#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

// More templates here

#define MAXLN (20)
#define MAXN (1000004)

int N;
int A[MAXN];
LL dp[MAXN];

int L[MAXN];
int MI[MAXLN][MAXN];
int MA[MAXLN][MAXN];

inline int query(int a, int b)
{
	int l = L[b-a+1];
	int n = 1 << l;
	return max(MA[l][a], MA[l][b+1-n]) - min(MI[l][a], MI[l][b+1-n]);
}

inline void check(int a, int b)
{
	if(a >= 0 && a < b) maxa(dp[b], dp[a] + query(a+1, b));
}

int main()
{
	cin >> N;
	FOR(i,1,N+1)
	{
		scanf("%d", A+i);
		MI[0][i] = MA[0][i] = A[i];
	}

	FOR(i,0,20) L[1<<i] = i;
	int l = 0;
	FOR(i,2,N+1)
	{
		if(L[i]) l = L[i];
		else L[i] = l;
	}
	FOR(i,1,20) FOR(j,1,N)
	{
		int a = min(N, j + (1<<(i-1)));
		MI[i][j] = min(MI[i-1][j], MI[i-1][a]);
		MA[i][j] = max(MA[i-1][j], MA[i-1][a]);
	}

	l = 0;
	FOR(i,1,N+1)
	{
		dp[i] = dp[i-1];
		check(l-1, i);
		check(l,   i);
		check(l+1, i);

		if(i == 1 || i == N || LL(A[i] - A[i-1]) * (A[i] - A[i+1]) >= 0) l = i;
	}
	cout << dp[N] << endl;

	return 0;
}