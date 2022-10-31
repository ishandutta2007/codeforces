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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

#define MAXN (202)

int N;
int A[MAXN];
int B[MAXN];
int C[MAXN];
int T[MAXN];
int V[MAXN];
int dt[MAXN];
int dfst;
LL lcm = 1;

void apply1(int *D, int *S)
{
	FOR(i,0,N) D[i] = S[D[i]];
}

void apply(int *D, int *S, LL k)
{
	if(k == 0) return;
	if(k%2 == 1)
	{
//		printf("D <- S\n");
		apply1(D, S);
	}

	FOR(i,0,N) T[i] = S[i];
//	printf("T <- S\n");
	apply1(T,S);
	FOR(i,0,N) S[i] = T[i];

	apply(D, S, k/2);
}

void dfs(int u)
{
//	printf("dfs %d\n", u+1);
	dt[u] = dfst++;
	V[u] = 1;
	if(!V[A[u]]) dfs(A[u]);
	else if(V[A[u]] == 1)
	{
//		printf("%d->%d len %d\n", u+1, A[u]+1, dfst - dt[A[u]]);
		LL len = dfst - dt[A[u]];
		LL g = __gcd<LL>(lcm, len);
		lcm *= len / g;
	}
	V[u] = 2;
}

int main()
{
	cin >> N;
	FOR(i,0,N)
	{
		int a;
		cin >> a;
		A[i] = B[i] = a-1;
	}

	FOR(i,0,N) if(V[i] == 0) dfs(i);

	LL sol = lcm;
	FOR(i,0,N) C[i] = i;
	apply(C, B, lcm);

//	FOR(i,0,N) printf("%d : %d\n", i+1, C[i]+1);

	while(1)
	{
		int okay = 1;
		FOR(i,0,N) if(C[i] != i && C[C[i]] != C[i]) okay = 0;
		if(okay) break;

		apply1(C, A);
		++sol;
	}

	cout << sol << endl;

	return 0;
}