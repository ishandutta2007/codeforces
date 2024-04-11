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

#define MAXN (200005)

int N, K;
PII P[MAXN];
int A[MAXN];
int B[MAXN];
LL sol = 1LL << 60;

void check(int n0)
{
	if(n0 > N) return;

	MIN_PQ(int) Q;
	int a = 0;
	int b = 0;
	int r = 0;
	FOR(i,0,N)
	{
		if(P[i]._1 == n0-1 || P[i]._1 == n0)
		{
			A[a++] = P[i]._2;
			++r;
		}
		else
		{
			B[b++] = P[i]._2;
			if(P[i]._1 > n0) ++r;
		}
	}
	sort(A, A+a, greater<int>());
	sort(B, B+b, greater<int>());

	LL res = 0;
	int n = 0;
	while(b > 0 && n < n0)
	{
		res += B[--b];
		++n;
	}
	while(n < n0)
	{
		res += A[--a];
		--r;
		++n;
	}

	if(r <= K) mina(sol, res);
	while(a > 0)
	{
		res += A[--a] - B[b++];
		--r;
		if(r <= K) mina(sol, res);
	}
}

int main()
{
	cin >> N >> K;
	FOR(i,0,N)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		P[i] = PII(a, b);
	}
	--K;

	sort(P, P+N, greater<PII>());
	if(P[K]._1 > N)
	{
		printf("-1\n");
		return 0;
	}

	check(P[K]._1);
	check(P[K]._1+1);
	check(P[K]._1+2);
	cout << sol << endl;

	return 0;
}