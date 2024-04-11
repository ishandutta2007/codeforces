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

LL A[4];

int main()
{
	FOR(i,0,4) cin >> A[i];
	LL B[2];
	FOR(i,0,2)
	{
		B[i] = 1;
		FOR(j,0,2)
		{
			int a = A[i*2 + j];
			while(a % 2 == 0) a /= 2;
			while(a % 3 == 0) a /= 3;
			B[i] *= a;
		}
	}

	if(B[0] != B[1])
	{
		printf("-1\n");
		return 0;
	}

	LL g = __gcd(A[0]*A[1], A[2]*A[3]);
	int sol = 0;
	FOR(i,0,2)
	{
		LL d = A[2*i] * A[2*i+1] / g;
		while(d % 3 == 0)
		{
			++sol;
			d /= 3;
			if(A[2*i] % 3 == 0) A[2*i] = A[2*i] * 2 / 3;
			else A[2*i+1] = A[2*i+1] * 2 / 3;
		}
	}
	
	g = __gcd(A[0]*A[1], A[2]*A[3]);
	FOR(i,0,2)
	{
		LL d = A[2*i] * A[2*i+1] / g;
		while(d % 2 == 0)
		{
			++sol;
			d /= 2;
			if(A[2*i] % 2 == 0) A[2*i] /= 2;
			else A[2*i+1] /= 2;
		}
	}

	printf("%d\n", sol);
	printf("%I64d %I64d\n", A[0], A[1]);
	printf("%I64d %I64d\n", A[2], A[3]);

	return 0;
}