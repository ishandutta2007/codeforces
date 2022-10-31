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

#define MAXN (100004)

int N, Q;
VI E[MAXN];
int V[MAXN];
int S[MAXN];

int EX[MAXN];
int EL[MAXN];
double EU[MAXN];

void dfs(int u)
{
	V[u] = 1;
	S[u] = 1;
	for(int e: E[u])
	{
		int v = u ^ EX[e];
		if(!V[v])
		{
			dfs(v);
			EU[e] = S[v];
			S[u] += S[v];
		}
	}
}

inline double f(int e)
{
	double a = EU[e];
	double b = N - a;
	return EL[e] * (a * b * (a+b-2));
}

int main()
{
	cin >> N;
	FOR(i,1,N)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		EX[i] = a^b;
		EL[i] = c;
		E[a].PB(i);
		E[b].PB(i);
	}
	dfs(1);

	double sol = 0;
	FOR(i,1,N) sol += f(i);
	double C = N*double(N-1)*double(N-2)/6.0;
	sol /= C;

	cin >> Q;
	FOR(i,0,Q)
	{
		int e, w;
		scanf("%d %d", &e, &w);
		double t = -f(e);
		EL[e] = w;
		t += f(e);
		sol += t / C;
		printf("%.10lf\n", sol);
	}

	return 0;
}