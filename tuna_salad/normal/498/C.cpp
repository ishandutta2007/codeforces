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

#define MAXN (104)
#define MAXM (104)
#define MAXE (304)

int N, M;
int A[MAXN];
int B[MAXN];
int X[MAXM];
int Y[MAXM];

map <int,int> C;

VI E[MAXN];
int EX[MAXE];
int EC[MAXE];
int EF[MAXE];
int EN;

int SA, SB;
int V[MAXN];
int rit;

void addE(int a, int b)
{
	++EN;
	EX[EN] = a^b;;
	E[a].PB(EN);
	E[b].PB(-EN);
}

int dfs(int u, int c)
{
	if(u == SB) return c;
	V[u] = rit;

	for(int e: E[u])
	{
		if(e > 0)
		{
			int v = EX[e] ^ u;
			if(V[v] != rit && EC[e] > 0)
			{
				int r = dfs(v, min(c, EC[e]));
				if(r)
				{
					EC[e] -= r;
					EF[e] += r;
					return r;
				}
			}
		}
		else
		{
			e = -e;
			int v = EX[e] ^ u;
			if(V[v] != rit && EF[e] > 0)
			{
				int r = dfs(v, min(c, EF[e]));
				if(r)
				{
					EF[e] -= r;
					EC[e] += r;
					return r;
				}
			}
		}
	}
	return 0;
}

int flow()
{
	int res = 0;
	while(1)
	{
		++rit;
		int r = dfs(SA, 1e6);
		if(!r) break;
		res += r;
	}
	return res;
}

int main()
{
	cin >> N >> M;
	FOR(i,1,N+1)
	{
		int a;
		cin >> a;
		A[i] = a;
		if(a % 2 == 0)
		{
			++C[2];
			while(a % 2 == 0) a/=2;
		}

		for(int j = 3; j*j <= a; j += 2)
		{
			if(a % j == 0)
			{
				++C[j];
				a/=j;
				while(a % j == 0) a/=j;
			}
		}
		if(a > 1) ++C[a];
	}

	SA = N+1;
	SB = N+2;
	FOR(i,1,N+1)
	{
		if(i&1) addE(SA, i);
		else addE(i, SB);
	}
	FOR(i,0,M)
	{
		int a, b;
		cin >> a >> b;
		if(b&1) swap(a,b);
		addE(a, b);
	}

	int sol = 0;
	for(PII p: C) if(p._2 > 1)
	{
		int n = p._1;

		FOR(i,1,N+1)
		{
			int a = A[i];
			int c = 0;
			while(a % n == 0)
			{
				a /= n;
				++c;
			}
			EC[i] = c;
			EF[i] = 0;
		}
		FOR(i,N+1,EN+1)
		{
			EC[i] = 1e6;
			EF[i] = 0;
		}
		sol += flow();
	}
	cout << sol << endl;

	return 0;
}