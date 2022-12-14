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
const int MAXN = 100007;
const int MAXL = 61;

int n;
LL a[MAXN];
int ka, kp;
LL ans[MAXN], pans[MAXN];

void init ();
void input ();
void work ();



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
}

void input ()
{
	// input method

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%I64d", &a[i] );
}

void work ()
{
	// main work

	sort ( a + 1, a + 1 + n );
	reverse ( a + 1, a + 1 + n );

	int ni = 1;
	ka = 0;
	lpdi ( i, MAXL - 1, 0 ) {
		if ( a[ni] >> i & 1 ) {
			kp = ka;
			ka = 0;
			memcpy ( pans, ans, sizeof ( pans ) );
			int ip = 1, nv = 0;
			while ( ( a[ni] >> i & 1 ) && ip <= kp ) {
				if ( !nv ) {
					ans[++ka] = a[ni];
					++ni;
					nv ^= 1;
				} else {
					ans[++ka] = pans[ip];
					if ( pans[ip] >> i & 1 ) nv ^= 1;
					++ip;
				}
			}
			while ( ( a[ni] >> i & 1 ) && !nv ) {
				ans[++ka] = a[ni];
				++ni;
				nv ^= 1;
			}
			while ( ip <= kp ) {
				ans[++ka] = pans[ip];
				++ip;
			}
			if ( a[ni] >> i & 1 ) {
				printf ( "No\n" );
				return;
			}
		}
	}

	printf ( "Yes\n" );
	lpi ( i, 1, n ) printf ( "%I64d ", ans[i] ); putchar ( '\n' );
}