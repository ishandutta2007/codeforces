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

#define MAXN (6004)

int N;
int P[MAXN];
int V[MAXN];
VI E[MAXN];

int sol;
int n;
int A[MAXN];

void dfs(int u)
{
	V[u] = 1;
	int p = lower_bound(A, A+n, P[u]) - A;
	int n1 = n;
	int a1 = A[p];
	A[p] = P[u];
	if(p == n) ++n;
	maxa(sol, n);

	for(int v: E[u]) if(!V[v]) dfs(v);

	n = n1;
	A[p] = a1;
	V[u] = 0;
}

int main()
{
	cin >> N;
	FOR(i,1,N+1) scanf("%d", P+i);
	FOR(i,1,N)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		E[a].PB(b);
		E[b].PB(a);
	}

	A[0] = -1;
	n = 1;
	sol = 0;
	FOR(i,1,N+1)
	{
		dfs(i);
	}
	cout << sol-1 << endl;

	return 0;
}