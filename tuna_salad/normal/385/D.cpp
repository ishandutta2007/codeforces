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

#define MAXN (24)
#define MAX2N (1 << 20)

const double PI = acos(-1);

int N;
double L, R;
double X[MAXN];
double Y[MAXN];
double A[MAXN];

double dp[MAX2N];

double calcl(double l, int id)
{
	double ang = atan2(-Y[id], l - X[id]) + A[id];
	if(ang >= 0) return R;
	else return min(R, X[id] - Y[id] * cos(ang) / sin(ang));
}

int main()
{
	cin >> N >> L >> R;
	FOR(i,0,N)
	{
		cin >> X[i] >> Y[i] >> A[i];
		A[i] *= PI / 180.;
	}

	int N1 = 1<<N;

	FOR(i,0,N1)
	{
		dp[i] = L;
		int b = i;
		while(b > 0)
		{
			int j = __builtin_ctz(b);
			b ^= 1<<j;

			int ii = i ^ (1<<j);
			maxa(dp[i], calcl(dp[ii], j));
		}
	}

	double sol = 0;
	FOR(b,0,N1) maxa(sol, dp[b] - L);
	printf("%.9lf\n", sol);

	return 0;
}