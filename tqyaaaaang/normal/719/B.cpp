#include <bits/stdc++.h>
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
const int MAXN = 100007;

const char CH[2] = { 'r', 'b' };

int n;
char s[MAXN];

void init ();
void input ();
void work ();

int getans ( int fir );



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
	
	cin >> n >> s;
}

void work ()
{
	// main work

	cout << qmin ( getans ( 0 ), getans ( 1 ) ) << endl;
}



int getans ( int fir )
{
	int cc[2] = { 0 };

	lp ( i, 0, n ){
		if ( s[i] ^ CH[fir^(i&1)] ) ++cc[i&1];
	}

	return qmax ( cc[0], cc[1] );
}