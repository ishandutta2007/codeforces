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
#define MAXM (100004)

int N, M;
int B[MAXN];
int D[MAXM];
int K[MAXM];

PII P[MAXN+MAXM];
int sol[MAXN];

int main()
{
	cin >> N;
	int j = 0;
	FOR(i,1,N+1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		P[j++] = PII(a, i);
		B[i] = b;
	}

	cin >> M;
	FOR(i,1,M+1)
	{
		int c, d, k;
		scanf("%d %d %d", &c, &d, &k);
		P[j++] = PII(c, -i);
		D[i] = d;
		K[i] = k;
	}

	int hasSol = 1;
	set <PII> S;
	sort(P, P+j);
	FOR(i,0,j)
	{
		if(P[i]._2 < 0)
		{
			int id = -P[i]._2;
			S.insert(PII(D[id], id));
		}
		else
		{
			int id = P[i]._2;
			auto si = S.lower_bound(PII(B[id], 0));
			if(si == S.end())
			{
				hasSol = 0;
				break;
			}

			sol[id] = si->_2;
			if(--K[si->_2] == 0) S.erase(si);
		}
	}

	if(hasSol)
	{
		printf("YES\n");
		FOR(i,1,N+1) printf("%d ", sol[i]);
		cout << endl;
	}
	else printf("NO\n");

	return 0;
}