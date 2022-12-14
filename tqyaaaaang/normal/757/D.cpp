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
const int MAXN = 79;
const int MAXM = 20;
const int MAXS = ( 1 << 20 ) + 7;
const int MOD = 1e9 + 7;
const int MAXL = 5;

int n;
char s[MAXN];
int num[MAXN];
int dp[MAXN][MAXS];
int pn[MAXN][MAXN];
int beg[MAXN];

void init ();
void input ();
void work ();



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
}

void input ()
{
	// input method

	scanf ( "%d%s", &n, s );
}

void work ()
{
	// main work

	lp ( i, 0, n ) num[i+1] = s[i] - '0';

	int np;
	lp ( i, 0, n ){
/*		pn[i][1] = num[i+1];
		lpi ( j, 2, MAXL ){
			//if ( i - j < 0 ) pn[i][j] = -1;
			//else{
			//	pn[i][j] = 0;
			//	lpi ( k, i-j+1, i ) if ( num[k] ) pn[i][j] += 1 << ( k - ( i - j ) );
			//}

			if ( i + j > n ) pn[i][j] = -1;
			else{
				pn[i][j] = ( pn[i][j-1] << 1 ) + ( num[i+j] ? 1 : 0 );
			}
		}*/

		np = i + 1;
		while ( np <= n && !num[np] ) ++np;

		beg[i] = np;

		if ( np <= n ){
			pn[i][np] = 1;
			lp ( j, 1, MAXL ){
				if ( np + j > n ) pn[i][np+j] = -1;
				else{
					pn[i][np+j] = ( pn[i][np+j-1] << 1 ) + num[np+j];
				}
			}
		}
	}

	INIT ( dp, 0 );
	lpi ( i, 0, n ) dp[i][0] = 1;
	int ms = 1 << MAXM, vs;
	lp ( i, 0, n ){
		lp ( sta, 0, ms ){
/*			lpi ( j, 1, MAXL ){
				if ( i - j < 0 ) break;
				if ( pn[i][j] > MAXM ) continue;

				dp[i][sta]
			}*/
//			lpi ( j, 1, MAXL ){
			lp ( j, beg[i], beg[i]+MAXL ){
/*				if ( i + j > n ) break;
				if ( pn[i][j] > MAXM ) continue;
				if ( !pn[i][j] ) continue;

				v = i + j;
				vs = sta | ( 1 << ( pn[i][j] - 1 ) );
				dp[v][vs] = ( dp[v][vs] + dp[i][sta] ) % MOD;*/

				if ( j > n ) break;
				if ( pn[i][j] > MAXM ) continue;

				vs = sta | ( 1 << ( pn[i][j] - 1 ) );
				dp[j][vs] = ( dp[j][vs] + dp[i][sta] ) % MOD;
			}
		}
	}

	int ns, ans = 0;
	lpi ( i, 1, n ){
		ns = 0;
		lp ( j, 0, MAXM ){
			ns ^= ( 1 << j );
			ans = ( ans + dp[i][ns] ) % MOD;
		}
	}

	printf ( "%d\n", ans );
}