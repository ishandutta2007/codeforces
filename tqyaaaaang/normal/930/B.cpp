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
const int MAXN = 10007;
const int BASE = 26;

int n;
int a[MAXN];
char s[MAXN];
int cc[BASE];

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

	scanf ( "%s", &s );
}

void work ()
{
	// main work

	n = strlen ( s );
	lp ( i, 0, n ) a[i] = s[i] - 'a';
	lp ( i, 0, n ) a[i + n] = a[i];

	int ans = 0, maxi, cur;
	lp ( c, 0, BASE ) {
		AR ( int ) p;
		lpi ( i, 1, n ) {
			if ( a[i] == c ) p.push_back ( i );
		}

		int size = p.size ();
		maxi = 0;
		lp ( i, 0, n ) {
			INIT ( cc, 0 );
			lp ( j, 0, size ) ++cc[a[p[j] + i]];
			cur = 0;
			lp ( j, 0, BASE ) if ( cc[j] == 1 ) ++cur;
			maxi = qmax ( maxi, cur );
		}
		ans += maxi;
	}

	cout << setprecision ( 13 ) << fixed << SC ( LD, ans ) / n << endl;
}