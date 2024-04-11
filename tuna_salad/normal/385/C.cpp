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

#define MAXA (20000004)
#define MAXP (10004)

int N, M;

int A[MAXA];
int P[MAXP];
int P2[MAXP];
int pn;

int main()
{
	P[0] = 2;
	P2[0] = 4;
	pn = 1;
	for(int i = 3; i < MAXP; i += 2)
	{
		int p = 1;
		for(int j = 0; j < pn && P2[j] <= i; ++j) if(i % P[j] == 0)
		{
			p = 0;
			break;
		}
		if(p)
		{
			P[pn] = i;
			P2[pn] = i*i;
			++pn;
		}
	}

	cin >> N;
	FOR(i,0,N)
	{
		int a;
		scanf("%d", &a);
		++A[a];
	}

	FOR(i,2,MAXA) if(A[i])
	{
		int c = A[i];
		A[i] = 0;
		int a = i;
		for(int j = 0; P2[j] <= a; ++j)
		{
			if(a % P[j] == 0)
			{
				A[P[j]] += c;
				while(a % P[j] == 0) a /= P[j];
			}
		}
		if(a > 1) A[a] += c;
	}

	FOR(i,2,MAXA) A[i] += A[i-1];

	cin >> M;
	FOR(i,0,M)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		r = min(r, int(2e7));

		if(l > r) printf("0\n");
		else printf("%d\n", A[r] - A[l-1]);
	}

	return 0;
}