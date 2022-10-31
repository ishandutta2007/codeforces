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

#define MAXN (304)

int N;
int A[MAXN];
char S[MAXN][MAXN];
int V[MAXN];

int B[MAXN];
int P[MAXN];
int bn;

int sol[MAXN];

void rec(int u)
{
	V[u] = 1;
	B[bn] = A[u];
	P[bn] = u;
	++bn;
	FOR(i,0,N) if(S[u][i] == '1' && !V[i]) rec(i);
}

int main()
{
	cin >> N;
	FOR(i,0,N) cin >> A[i];
	FOR(i,0,N) scanf("%s", S[i]);

	FOR(i,0,N) if(!V[i])
	{
		bn = 0;
		rec(i);

		sort(B, B+bn);
		sort(P, P+bn);
		FOR(i,0,bn) sol[P[i]] = B[i];
	}
	FOR(i,0,N) printf("%d ", sol[i]);
	cout << endl;

	return 0;
}