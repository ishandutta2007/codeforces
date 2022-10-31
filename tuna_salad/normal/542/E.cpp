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

#define MAXN (1004)
#define MAXM (100004)

int N, M;
VI E[MAXN];
int C[MAXN];

int rit;
int V[MAXN];
int dist[MAXN];
int A[MAXN];
int an;

int sol;
int Q[MAXN];
int qt;
int qh;

inline int empty()
{
	return qt == qh;
}

inline void enqueue(int a)
{
	Q[qt++] = a;
	if(qt == MAXN) qt = 0;
}

inline int dequeue()
{
	int res = Q[qh++];
	if(qh == MAXN) qh = 0;
	return res;
}

int dfs1(int u, int c)
{
//	printf("%d %d\n", u+1, c);
	V[u] = 1;
	C[u] = c;
	A[an++] = u;
	for(int v: E[u])
	{
		if(V[v] == 1 && C[v] == c) return 0;
		if(V[v] != 1 && !dfs1(v, !c)) return 0;
	}
	return 1;
}

int main()
{
	cin >> N >> M;
	FOR(i,0,M)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		E[a].PB(b);
		E[b].PB(a);
	}

	FOR(i,0,N) if(V[i] == 0)
	{
		if(!dfs1(i,0))
		{
			printf("-1\n");
			return 0;
		}
		int res = 0;
		FOR(j,0,an)
		{
			MSET(dist, 1);
			dist[A[j]] = 0;
			qh = qt = 0;
			enqueue(A[j]);
			while(!empty())
			{
				int u = dequeue();
				for(int v: E[u]) if(mina(dist[v], dist[u]+1)) enqueue(v);
			}
			FOR(k,0,an) maxa(res, dist[A[k]]);
		}
		sol += res;
		an = 0;
	}

	cout << sol << endl;

	return 0;
}