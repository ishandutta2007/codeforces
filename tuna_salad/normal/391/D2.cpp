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
typedef pair<int,int> PII; typedef pair<int,PII> PIP;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

// More templates here

#define MAXN (50004)
#define MAXM (50004)
#define MAXB (150004)

int N, M;
int X1[MAXN], Y1[MAXN], L1[MAXN];
int X2[MAXM], Y2[MAXM], L2[MAXM];

PIP E[MAXB];

int B[MAXB];

int read_bit(int p)
{
	int res = 0;
	while(p > 0)
	{
		res += B[p];
		p -= p & -p;
	}
	return res;
}

void update_bit(int p, int v)
{
	while(p < MAXB)
	{
		B[p] += v;
		p += p & -p;
	}
}

int check(int L)
{
	const int I = 1e9;
	int en = 0;
	set <int> S1;
	map <int,int> S2;

	FOR(i,0,N) if(L1[i] >= L+L)
	{
		S1.insert(Y1[i] + L);
		S1.insert(Y1[i] + L1[i] - L);
	}
	FOR(i,0,M) if(L2[i] >= L+L)
	{
		S1.insert(Y2[i]);
	}

	{
		int i = 0;
		for(int s: S1) S2[s] = ++i;
	}

	FOR(i,0,N) if(L1[i] >= L+L)
	{
		E[en++] = PIP(X1[i], PII(S2[Y1[i] + L], S2[Y1[i] + L1[i] - L]));
	}
	FOR(i,0,M) if(L2[i] >= L+L)
	{
		int t = S2[Y2[i]];
		E[en++] = PIP(X2[i] + L, PII(-I, t));
		E[en++] = PIP(X2[i] + L2[i] - L, PII(I, t));
	}
	sort(E, E+en);

	int res = 0;
	FOR(i,0,en)
	{
		if(E[i]._2._1 == -I)
		{
			update_bit(E[i]._2._2, 1);
		}
		else if(E[i]._2._1 == I)
		{
			update_bit(E[i]._2._2, -1);
		}
		else if(!res)
		{
			int r = read_bit(E[i]._2._2) - read_bit(E[i]._2._1 - 1);
			if(r > 0) res = 1;
		}
	}

	return res;
}

int main()
{
	cin >> N >> M;
	FOR(i,0,N) scanf("%d %d %d", X1+i, Y1+i, L1+i);
	FOR(i,0,M) scanf("%d %d %d", X2+i, Y2+i, L2+i);

	int sol = 0;
	int lb = 1;
	int rb = 5e7;
	while(lb <= rb)
	{
		int mid = (lb + rb) / 2;
		if(check(mid))
		{
			sol = mid;
			lb = mid + 1;
		}
		else
			rb = mid - 1;
	}
	cout << sol << endl;

	return 0;
}