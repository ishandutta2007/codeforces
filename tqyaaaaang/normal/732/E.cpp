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
const int MAXN = 200007;

struct cT
{
	cT () : cho ( 0 ) {}

	int id, p, cho;
}com[MAXN];

struct qT
{
	qT () {}

	qT ( int _id, int _p, int _cc ) : id ( _id ), p ( _p ), cc ( _cc ) {}

	bool operator < ( const qT &a ) const
	{
		return ( ( p ^ a.p ) ? ( p < a.p ) : ( ( cc ^ a.cc ) ? ( cc > a.cc ) : ( id > a.id ) ) );
	}

	int id, p, cc;
}now;

int n, m;
int s[MAXN], ad[MAXN];
priority_queue < qT > q;


void init ();
void input ();
void work ();

bool cmp_s ( const cT &a, const cT &b )
{
	return ( ( a.p ^ b.p ) ? ( a.p > b.p ) : ( a.id > b.id ) );
}

bool cmp_id ( const cT &a, const cT &b )
{
	return ( a.id < b.id );
}



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
	lp ( i, 0, n ) scanf ( "%d", &com[i].p );
	lpi ( i, 1, m ) scanf ( "%d", &s[i] );
}

void work ()
{
	// main work

	lp ( i, 0, n ) com[i].id = i;

	sort ( com, com+n, cmp_s );

	lpi ( i, 1, m ) q.push ( qT ( i, s[i], 0 ) );

	memset ( ad, 0, sizeof ( ad ) );
	int ans = 0, ok = 0;
	lp ( i, 0, n ){
		while ( 1 ){
			if ( q.empty() ) break;

			now = q.top();

			if ( now.p > com[i].p ){
				now.p = ( now.p + 1 ) / 2;
				++now.cc;
				q.pop();
				q.push ( now );
			}else if ( now.p == com[i].p ){
				q.pop();
				com[i].cho = now.id;
				ans += now.cc;
				ad[now.id] = now.cc;
				++ok;
				break;
			}else{
				break;
			}
		}

		if ( q.empty() ) break;
	}

	sort ( com, com+n, cmp_id );

	printf ( "%d %d\n", ok, ans );
	lpi ( i, 1, m ) printf ( "%d ", ad[i] );
	printf ( "\n" );
	lp ( i, 0, n ) printf ( "%d ", com[i].cho );
	printf ( "\n" );
}