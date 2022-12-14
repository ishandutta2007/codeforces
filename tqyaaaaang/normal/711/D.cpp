// I/O stream
#include <iostream>
#include <iomanip>

// Algorithms & Maths
#include <cmath>
#include <numeric>
#include <algorithm>

// C headers
#include <cstdlib>
#include <cstdio>

// String
#include <string>
#include <cstring>

// STL
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

// Exeption
#include <exception>
#include <stdexcept>
#include <cassert>

using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 200007;
const int MAXE = MAXN*2;
const int MOD = 1e9 + 7;

int n, k = 0, top = 0, ac = 0, v;
LL e2[MAXN];
int edge[MAXE];
int nxt[MAXE];
int last[MAXN];
int s[MAXN];
bool vis[MAXN];
bool ena[MAXE];
bool flag;
int cc[MAXN];



void init ();
void input ();
void work ();

void dfs ( int now );



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );

	e2[0] = 1;
	lp ( i, 1, MAXN )
		e2[i] = ( e2[i-1] << 1 ) % MOD;
}

void input ()
{
	// input method

	memset ( last, -1, sizeof ( last ) );

//	cin >> n;
	scanf ( "%d", &n );
	int v;
	lpi ( i, 1, n ){
		//cin >> v;
		scanf ( "%d", &v );
		edge[k] = v;
		nxt[k] = last[i];
		last[i] = k;
		++k;

		edge[k] = i;
		nxt[k] = last[v];
		last[v] = k;
		++k;
	}
}

void work ()
{
	// main work

	memset ( vis, false, sizeof ( vis ) );
	memset ( ena, true, sizeof ( ena ) );

	lpi ( i, 1, n ){
		if ( !vis[i] ){
			flag = false;
			top = 0;
			dfs ( i );
		}
	}

	LL ans = 1;
	int sum = 0;
	lp ( i, 0, ac ){
		sum += cc[i];
		ans *= ( e2[cc[i]] + MOD - 2 ) % MOD;
		ans %= MOD;
	}
	ans *= e2[n-sum];
	ans %= MOD;

	//cout << ans << endl;
	printf ( "%I64d\n", ans );
}



void dfs ( int now )
{
	vis[now] = true;
	if ( !flag ) s[top++] = now;

	for ( int i = last[now]; i ^ -1; i = nxt[i] ){
		if ( ena[i] ){
			v = edge[i];
			if ( !flag && vis[v] ){
				cc[ac] = 0;
				for ( --top; s[top] ^ v; ++cc[ac], --top );
				++cc[ac];
				++ac;
				flag = true;
			}else{
				ena[i^1] = false;
				dfs ( v );
			}
		}
	}

	if ( !flag ) --top;
}