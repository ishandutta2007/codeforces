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

int N, M;

int main()
{
	int t;
	cin >> t >> t;

	int mia = 2e9;
	int maa = -2e9;
	int mib = 2e9;
	int mab = -2e9;
	cin >> N;
	FOR(i,0,N)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int a = x+y;
		int b = x-y;
		mina(mia, a);
		maxa(maa, a);
		mina(mib, b);
		maxa(mab, b);
	}

	int sol = 2e9;
	int soli = 0;
	cin >> M;
	FOR(i,1,M+1)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int a = x+y;
		int b = x-y;
		int res = max(max(abs(mia-a), abs(maa-a)), max(abs(mib-b), abs(mab-b)));
		if(mina(sol, res)) soli = i;
	}

	printf("%d\n%d\n", sol, soli);

	return 0;
}