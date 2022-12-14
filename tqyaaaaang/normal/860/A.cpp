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
const int MAXN = 3007;

bool C[127];

int n;
char s[MAXN];
bool a[MAXN];

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

	C['a'] = C['e'] = C['i'] = C['o'] = C['u'] = true;
}

void input ()
{
	// input method

	scanf ( "%s", s );
}

void work ()
{
	// main work

	n = strlen ( s );

	int cc = 0;
	bool dif = false;
	lp ( i, 0, n ) {
		if ( !C[s[i]] ) {
			++cc;
			if ( i && !C[s[i-1]] && s[i] != s[i-1] ) {
				dif = true;
			}
			if ( cc >= 3 && dif ) {
				a[i] = true;
				cc = 1, dif = false;
			}
		} else {
			cc = 0, dif = false;
		}
	}

	lp ( i, 0, n ) {
		if ( a[i] ) putchar ( ' ' );
		putchar ( s[i] );
	}
	putchar ( '\n' );
}