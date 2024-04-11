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

char S[MAXN];

int main()
{
	scanf("%s", S);
	int N = strlen(S);
	int M = 0;
	FOR(i,0,N) if(S[i] == '#') ++M;

	int m = 0;
	int o = 0;
	int o2 = 0;
	int mo2 = 0;
	int valid = 1;

	FOR(i,0,N)
	{
		if(S[i] == '(')
		{
			++o;
			if(m == M) ++o2;
		}
		else if(o == 0)
		{
			valid = 0;
			break;
		}
		else
		{
			if(m == M) mina(mo2, --o2);
			if(S[i] == '#') ++m;
			--o;
		}
	}

	if(o2-mo2 > 0) valid = 0;
	if(valid)
	{
		FOR(i,0,M-1) printf("1\n");
		printf("%d\n", o + 1);
	}
	else
		printf("-1\n");

	return 0;
}