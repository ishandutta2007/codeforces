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
const int MAXN = 0;
const int WEEK = 7;
const int MAXL = 107;

char day1[MAXL], day2[MAXL];
char dayn[WEEK][MAXL] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
bool cr[WEEK] = { true, false, true, true, false, false, false };

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

	scanf ( "%s%s", day1, day2 );
}

void work ()
{
	// main work

	int d1, d2;
	lp ( i, 0, WEEK ){
		if ( !strcmp ( day1, dayn[i] ) ) d1 = i;
		if ( !strcmp ( day2, dayn[i] ) ) d2 = i;
	}

	int delta = ( d2 + WEEK - d1 ) % WEEK;
	printf ( cr[delta] ? "YES\n" : "NO\n" );
}