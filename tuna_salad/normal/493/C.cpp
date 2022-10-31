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

#define MAXNM (400004)

int N, M;
PII P[MAXNM];

int main()
{
	int j = 0;
	cin >> N;
	FOR(i,0,N)
	{
		int a;
		scanf("%d", &a);
		P[j++] = PII(a, 0);
	}
	cin >> M;
	FOR(i,N,N+M)
	{
		int a;
		scanf("%d", &a);
		P[j++] = PII(a, 1);
	}

	int sol = 0;
	int sola = 0;
	int solb = 0;
	sort(P, P+N+M);
	{
		j = N+M-1;
		int a = 0;
		int b = 0;
		while(j >= 0)
		{
			int i = j;
			while(i >= 0 && P[i]._1 == P[j]._1)
			{
				if(P[i]._2 == 0) ++a;
				else ++b;
				--i;
			}
			j = i;

			if(sol < a-b || (sol == a-b && sola < a))
			{
				sol = a-b;
				sola = a;
				solb = b;
			}
		}
	}
	printf("%d:%d\n", 2*N+sola, 2*M+solb);

	return 0;
}