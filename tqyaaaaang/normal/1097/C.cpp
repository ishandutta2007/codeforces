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
const int MAXL = 500007;

int n;
char buf[MAXL];
string s[MAXN];
int cl[MAXL], cr[MAXL], c0;

void init ();
void input ();
void work ();

bool isvalid ( const string &s )
{
	int nc = 0, n = s.size ();
	lp ( i, 0, n ) {
		if ( s[i] == '(' ) ++nc;
		else --nc;
		if ( nc < 0 ) return false;
	}
	return true;
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
}

void input ()
{
	// input method

	scanf ( "%d", &n );
	lpi ( i, 1, n ) {
		scanf ( "%s", buf );
		s[i] = buf;
	}
}

void work ()
{
	// main work

	int size, sum;
	string ts;
	lpi ( i, 1, n ) {
		size = s[i].size ();
		sum = 0;
		lp ( j, 0, size ) {
			if ( s[i][j] == '(' ) ++sum;
			else --sum;
		}
		if ( sum > 0 ) {
			if ( isvalid ( s[i] ) ) ++cl[sum];
		} else if ( sum < 0 ) {
			ts.resize ( size );
			lp ( j, 0, size ) ts[size - j - 1] = ( s[i][j] == '(' ) ? ')' : '(';
			if ( isvalid ( ts ) ) ++cr[-sum];
		} else {
			if ( isvalid ( s[i] ) ) ++c0;
		}
	}

	int ans = c0 >> 1;
	lp ( i, 0, MAXL ) ans += qmin ( cl[i], cr[i] );
	cout << ans << endl;
}