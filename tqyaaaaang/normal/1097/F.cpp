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

#define BS bitset < MAX >

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;
//#ifdef ONLINE_JUDGE
const int MAX = 7007;
//#else
//const int MAX = 10;
//#endif // !ONLINE_JUDGE

int n, q;
BS a[MAXN];
BS dc[MAX], coef[MAX];
int qtp, qa, qb, qc;
int asqr[MAX], kas;
bool mu2[MAX];

void init ();
void input ();
void inputq ();
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

	for ( int i = 1; i * i < MAX; ++i ) asqr[++kas] = i * i;

	lp ( i, 1, MAX ) {
		mu2[i] = 1;
		lpi ( j, 2, kas ) {   // skip asqr[1] = 1
			if ( i % asqr[j] == 0 ) {
				mu2[i] = 0;
				break;
			}
		}
	}

	lp ( i, 1, MAX ) {
		for ( int j = 1; i * j < MAX; ++j ) {
			if ( mu2[j] ) {
				coef[i][i*j] = 1;
			}
			dc[i*j][i] = 1;
		}
	}
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &q );
}

void inputq ()
{
	// input query

	scanf ( "%d%d%d", &qtp, &qa, &qb );
	if ( qtp == 2 || qtp == 3 ) scanf ( "%d", &qc );
}

void work ()
{
	// main work

	lp ( _q, 0, q ) {
		inputq ();

		if ( qtp == 1 ) {
			a[qa] = dc[qb];
		} else if ( qtp == 2 ) {
			a[qa] = a[qb] ^ a[qc];
		} else if ( qtp == 3 ) {
			a[qa] = a[qb] & a[qc];
		} else {
			putchar ( ( ( a[qa] & coef[qb] ).count () & 1 ) + '0' );
		}

//		cerr << "After " << _q + 1 << endl;
//		lpi ( i, 1, n ) { cerr << i << " : "; lp ( j, 0, MAX ) cerr << a[i][j]; cerr << endl; }
	}
}