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

#define MAXN (2000005)
#define MAXV (108)
#define MAXE (3000)

int N, K;
char A[MAXN];
char B[MAXN];
int X[64][64];

int D[MAXV];
int F[MAXV];
VI E[MAXV];
int ex[MAXE];
int W[MAXE];
int C[MAXE];
int en;

inline int f(char c)
{
	if(c >= 'a') return c - 'a';
	else return c - 'A' + 26;
}

inline char g(int a)
{
	if(a < 26) return a + 'a';
	else return a + 'A' - 26;
}

void add_edge(int a, int b, int w)
{
	E[a].PB(en);
	E[b].PB(-en);
	ex[en] = a^b;
	W[en] = w;
	C[en] = 1;
	++en;
}

int main()
{
	cin >> N >> K;
	scanf("%s %s", A, B);
	FOR(i,0,N) ++X[f(A[i])][f(B[i])];

	en = 1;
	int S = K*2;
	int T = S+1;
	FOR(i,0,K) FOR(j,0,K) add_edge(i, j+K, X[i][j]);
	FOR(i,0,K) add_edge(S, i, 0);
	FOR(i,0,K) add_edge(i+K, T, 0);

	int sol = 0;
	FOR(i,0,K)
	{
		FOR(i,0,T+1) D[i] = -1e8;
		D[S] = 0;

		MAX_PQ(PII) Q;
		Q.push(PII(0, S));
		while(!Q.empty())
		{
			PII p = Q.top(); Q.pop();
			if(D[p._2] != p._1) continue;

			int u = p._2;
			for(int e: E[u])
			{
				int v = ex[abs(e)] ^ u;
				if(e > 0)
				{
					if(C[e] && maxa(D[v], D[u] + W[e]))
					{
						Q.push(PII(D[v], v));
						F[v] = e;
					}
				}
				else
				{
					if(!C[-e] && maxa(D[v], D[u] - W[-e]))
					{
						Q.push(PII(D[v], v));
						F[v] = e;
					}
				}
			}
		}

		sol += D[T];
		int u = T;
		while(u != S)
		{
			int e = F[u];
			if(e > 0) C[e] = 0;
			else C[-e] = 1;
			u ^= ex[abs(e)];
		}
	}

	cout << sol << endl;
	FOR(i,0,K)
	{
		int a = 0;
		for(int e: E[i]) if(e > 0 && C[e] == 0)
		{
			a = ex[e] ^ i;
			break;
		}
		putchar(g(a-K));
	}
	cout << endl;

	return 0;
}