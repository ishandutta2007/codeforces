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
const int MAXN = 1007;
const int MAXQ = 23;
const int MAXL = 10;

int qlg[MAXN];

int n;
int ques[MAXN];
bool cho[MAXN];
int ret[MAXQ][MAXN];
int ans[MAXN];

void init ();
void input ();
void ask ( int id, int size );
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

	qlg[0] = 0, qlg[1] = 1;
	lp ( i, 2, MAXN ) qlg[i] = qlg[i>>1] + 1;
}

void input ()
{
	// input method

	scanf ( "%d", &n );
}

void ask ( int id, int size )
{
	if ( size ){
		printf ( "%d\n", size );
//		lpi ( i, 1, n ) if ( ques[i] ) printf ( "%d ", i );
		lp ( i, 0, size ) printf ( "%d ", ques[i] );
		putchar ( '\n' );
		fflush ( stdout );
		lpi ( i, 1, n ) scanf ( "%d", &ret[id][i] );
	}
}

void work ()
{
	// main work

	int g = qlg[n];

	INIT ( ret, 1111111 );
	int mod, k;
	lpi ( i, 1, g ){
		mod = 1 << i;

		INIT ( cho, false );
		lp ( i, 0, mod>>1 ) cho[i] = true;
		lp ( i, mod>>1, mod ) cho[i] = false;

		k = 0;
		lpi ( i, 1, n ) if ( cho[i%mod] ) ques[k++] = i;
		ask ( i<<1, k );

//		INIT ( cho, false );
		lp ( i, 0, mod ) cho[i] ^= true;

		k = 0;
		lpi ( i, 1, n ) if ( cho[i%mod] ) ques[k++] = i;
		ask ( i<<1^1, k );
	}

	lpi ( i, 1, n ){
		ans[i] = INF;
		lpi ( j, 1, g ){
			mod = 1 << j;
			if ( i % mod < mod >> 1 ) ans[i] = qmin ( ans[i], ret[j<<1^1][i] );
			else ans[i] = qmin ( ans[i], ret[j<<1][i] );
		}
	}

	printf ( "-1\n" );
	lpi ( i, 1, n ) printf ( "%d ", ans[i] );
	putchar ( '\n' );
	fflush ( stdout );
}