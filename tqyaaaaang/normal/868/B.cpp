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
const int MAXN = 0;

int h, m, s, t1, t2;

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

	cin >> h >> m >> s >> t1 >> t2;
}

void work ()
{
	// main work

	h %= 12, t1 %= 12, t2 %= 12;

	h = h * 3600 + m * 60 + s;
	m = ( m * 60 + s ) * 12;
	s *= 60 * 12;
	t1 *= 3600, t2 *= 3600;

	if ( t1 > t2 ) swap ( t1, t2 );

	bool f1 = true, f2 = true;
	if ( h > t1 && h < t2 ) f1 = false;
	else f2 = false;
	if ( m > t1 && m < t2 ) f1 = false;
	else f2 = false;
	if ( s > t1 && s < t2 ) f1 = false;
	else f2 = false;

	if ( f1 || f2 ) cout << "YES" << endl;
	else cout << "NO" << endl;
}