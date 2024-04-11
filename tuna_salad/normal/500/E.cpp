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


#define MAXN (200004)
#define MAX2 (20)

int N, Q;
int X[MAXN];
int L[MAXN];

int LF[MAXN]; // far right
int LN[MAXN]; // next

PII S[MAXN*2];
set <int> T;

PII J[MAX2][MAXN];

int main()
{
	cin >> N;
	int n = 0;
	FOR(i,1,N+1)
	{
		scanf("%d %d", X+i, L+i);
		S[n++] = PII(X[i], -i);
		S[n++] = PII(X[i]+L[i], i);
	}
	sort(S, S+n, greater<PII>());

	int last = N+1;
	FOR(i,0,n)
	{
		PII s = S[i];
		int id = abs(s._2);
		if(s._2 > 0) // tail
		{
			auto t = T.lower_bound(id);
			if(t != T.end())
			{
				LF[id] = LF[*t];
				LN[id] = LN[*t];
			}
			else
			{
				LF[id] = s._1;
				LN[id] = last;
			}
			T.insert(id);
		}
		else // head
		{
			T.erase(id);
			last = id;
		}
	}

	X[N+1] = 2e9 + 1;
	L[N+1] = 0;
	LF[N+1] = 2e9 + 1;
	LN[N+1] = N+1;
//	FOR(i,1,N+2) printf("%d : %d %d\n", i, LF[i], LN[i]);

	FOR(i,1,N+2) J[0][i] = PII(X[LN[i]] - LF[i], LN[i]);
	FOR(i,1,MAX2) FOR(j,1,N+2) J[i][j] = PII(J[i-1][j]._1 + J[i-1][J[i-1][j]._2]._1, J[i-1][J[i-1][j]._2]._2);

//	FOR(i,0,3) FOR(j,1,N+2) printf("%d %d : %d %d\n", i, j, J[i][j]._1, J[i][j]._2);

	cin >> Q;
	FOR(i,0,Q)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int res = 0;
		ROF(j,MAX2-1,-1)
		{
			if(J[j][a]._2 <= b)
			{
				res += J[j][a]._1;
				a = J[j][a]._2;
			}
		}
//		printf("   %d %d %d\n", a, b, J[0][a]._2);
		printf("%d\n", res);
	}

	return 0;
}