#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
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
const int MAXN = 2007;
const int MAXS = 807;
const int MAX = 10;

struct qT
{
	void setd ( int _i, int _j, int _k )
	{
		i = _i, j = _j, k = _k;
	}

	int i, j, k;
}q[MAXN*MAXS*MAX];

int n;
int pu[MAXN], pv[MAXN];
int sti[MAX+1][MAX+1][MAX+1][MAX+1], its[MAXS][4], ks;
int dp[MAXN][MAXS][MAX];

void init ();
void input ();
void work ();

int enc ( int a[] )
{
	sort ( a, a + 4 );
	return sti[a[0]][a[1]][a[2]][a[3]];
}

void dec ( int id, int a[] )
{
	lp ( i, 0, 4 ) a[i] = its[id][i];
}



int main ()
{
	init ();
	input ();
	work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );

	ks = 0;
	lpi ( a, 1, MAX ) lpi ( b, a, MAX ) lpi ( c, b, MAX ) lpi ( d, c, MAX ) sti[a][b][c][d] = ++ks, its[ks][0] = a, its[ks][1] = b, its[ks][2] = c, its[ks][3] = d;
//	cerr << ks << endl;
}

void input ()
{
	// input method

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d%d", &pu[i], &pv[i] );
}

void work ()
{
	// main work

	INIT ( dp, -1 );
	int l = 0, r = 0, now, nl, v;
	int ns[4] = { 10, 10, 10, 10 }, vs[4], ni = enc ( ns ), vi, nv;
	dp[0][ni][1] = 0;
	q[r++].setd ( 0, ni, 1 );
	bool flag;
	while ( l < r ) {
		now = q[l].i, dec ( q[l].j, ns ), nl = q[l].k, nv = dp[q[l].i][q[l].j][q[l].k], ++l;
		ni = enc ( ns );
		lp ( i, 0, 4 ) {
			if ( ns[i] == nl ) {
				lp ( j, 0, 4 ) vs[j] = ns[j];
				vs[i] = 10;
				vi = enc ( vs );
				if ( dp[now][vi][nl] == -1 ) dp[now][vi][nl] = nv + 1, q[r++].setd ( now, vi, nl );
			}
		}
		if ( now < n && pu[now + 1] == nl && ns[3] == 10 ) {
			lp ( i, 0, 4 ) vs[i] = ns[i];
			lp ( i, 0, 4 ) {
				if ( vs[i] == 10 ) {
					vs[i] = pv[now + 1];
					break;
				}
			}
			vi = enc ( vs );
			if ( dp[now + 1][vi][nl] == -1 ) dp[now + 1][vi][nl] = nv + 1, q[r++].setd ( now + 1, vi, nl );
		}
		if ( nl > 1 ) {
			if ( dp[now][ni][nl - 1] == -1 ) dp[now][ni][nl - 1] = nv + 1, q[r++].setd ( now, ni, nl - 1 );
		}
		if ( nl < 9 ) {
			if ( dp[now][ni][nl + 1] == -1 ) dp[now][ni][nl + 1] = nv + 1, q[r++].setd ( now, ni, nl + 1 );
		}
	}

	lp ( i, 0, 4 ) ns[i] = 10;
	ni = enc ( ns );
	int ans = INF;
	lp ( i, 1, MAX ) ans = qmin ( ans, dp[n][ni][i] );
	cout << ans << endl;
}