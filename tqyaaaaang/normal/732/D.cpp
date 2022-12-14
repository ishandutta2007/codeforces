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

int n, m, ko;
int d[MAXN], a[MAXN];
bool vis[MAXN];
int ord[MAXN];
int t[MAXN];

void init ();
void input ();
void work ();

bool check ( int tst );



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

	scanf ( "%d%d", &n, &m );

	lpi ( i, 1, n ) scanf ( "%d", &d[i] );
	lpi ( i, 1, m ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	if ( !check ( n ) ){
		printf ( "-1\n" );
		return;
	}

	int l = 1, r = n, mid;
	while ( l < r ){
		mid = ( l + r ) >> 1;
		if ( check ( mid ) )
			r = mid;
		else
			l = mid + 1;
	}

	printf ( "%d\n", l );
}



bool check ( int tst )
{
	memset ( vis, false, sizeof ( vis ) );
	ko = 0;
	lpd ( i, tst, 0 )
		if ( d[i] && !vis[d[i]] ) vis[d[i]] = true, ord[ko++] = d[i], t[d[i]] = i;

	if ( ko ^ m ) return false;

	int left = 0, now = 0;
	lpdi ( i, ko-1, 0 ){
		left += t[ord[i]]-now-1;

		if ( left < a[ord[i]] ) return false;
		left -= a[ord[i]];
		now = t[ord[i]];
	}

	return true;
}