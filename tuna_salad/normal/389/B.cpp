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

#define MAXN (104)

const int dr[5] = {0, 0, 1, 0, -1};
const int dc[5] = {0, 1, 0, -1, 0};

int N;
char B[MAXN][MAXN];

int main()
{
	cin >> N;
	FOR(i,0,N) scanf("%s", B[i]);
	FOR(i,1,N-1) FOR(j,1,N-1)
	{
		int n = 0;
		FOR(k,0,5)
		{
			int r = i + dr[k];
			int c = j + dc[k];
			n += B[r][c] == '#';
		}
		if(n == 5)
		{
			FOR(k,0,5)
			{
				int r = i + dr[k];
				int c = j + dc[k];
				B[r][c] = '.';
			}
		}
	}

	int valid = 1;
	FOR(i,0,N) FOR(j,0,N) if(B[i][j] != '.') valid = 0;
	if(valid) printf("YES\n");
	else printf("NO\n");

	return 0;
}