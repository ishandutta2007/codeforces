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

int N, M;
int L[MAXN];
PII S[MAXN];

int NL[MAXN];

int main()
{
	cin >> N >> M;

	int A = 0;
	FOR(i,0,M)
	{
		int a;
		char s[4];
		scanf("%s %d", s, &a);
		if(s[0] == '+')
		{
			S[i] = PII(1, a);
			L[a] = 1;
		}
		else
		{
			S[i] = PII(2, a);
			if(L[a] == 0) ++A;
			L[a] = 2;
		}
	}

	int a = A;
	FOR(i,0,M)
	{
		if(S[i]._1 == 1)
		{
			if(a > 0 || (i > 0 && S[i-1]._2 != S[i]._2)) NL[S[i]._2] = 1;
			++a;
		}
		else
		{
			--a;
			if(a > 0 || (i+1 < M && S[i+1]._2 != S[i]._2)) NL[S[i]._2] = 1;
		}
	}

	int c = N;
	FOR(i,1,N+1) c -= NL[i];
	cout << c << endl;
	if(c > 0)
	{
		FOR(i,1,N+1) if(!NL[i]) printf("%d ", i);
		cout << endl;
	}

	return 0;
}