// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

const LL infll = 1LL << 50;

#define MAXN (200005)

int N;
int A[MAXN];
LL B[MAXN][4]; // 2 is unused
VI E[MAXN];

LL sol;

LL b0, b1, t;
void dfs(int u)
{
	for(int v: E[u]) dfs(v);

	B[u][0] = 0;
	B[u][1] = -infll;
	for(int v: E[u])
	{
		t = max(B[v][1], B[v][3]);
		b0 = max(B[u][0] + B[v][0], B[u][1] + t);
		b1 = max(B[u][0] + t, B[u][1] + B[v][0]);
		B[u][0] = b0;
		B[u][1] = b1;
	}
	maxa(sol, max(B[u][1], B[u][3] = B[u][0] + A[u]));
}

int main()
{
	cin >> N;
	FOR(i,0,N)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		A[i] = b;
		if(a >= 0) E[a].PB(i);
	}

	dfs(0);
	cout << sol << endl;

	return 0;
}