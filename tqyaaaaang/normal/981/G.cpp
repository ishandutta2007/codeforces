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
const int MAXN = 200007;
const int MAX = 262144;
const int MAXS = MAX * 2 + 7;
const int MOD = 998244353;



int add ( int x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
	return x;
}

void addv ( int &x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
}

int dec ( int x, int y )
{
	x -= y;
	if ( x < 0 ) x += MOD;
	return x;
}

void decv ( int &x, int y )
{
	x -= y;
	if ( x < 0 ) x += MOD;
}



class stT
{
public:
	stT ()
	{
		fill ( mult, mult + MAXS, 1 );
	}

	void add1 ( int l, int r, int now = 1, int ll = 1, int rr = MAX )
	{
		if ( l > r ) return;
		if ( ll >= l && rr <= r ) addv ( data[now], rr - ll + 1 ), addv ( addt[now], 1 );
		else if ( rr < l || ll > r ) return;
		else {
			int mid = ( ll + rr ) >> 1;
			downtag ( now, rr - ll + 1 );
			add1 ( l, r, now << 1, ll, mid );
			add1 ( l, r, now << 1 | 1, mid + 1, rr );
			data[now] = add ( data[now << 1], data[now << 1 | 1] );
		}
	}

	void mul2 ( int l, int r, int now = 1, int ll = 1, int rr = MAX )
	{
		if ( l > r ) return;
		if ( ll >= l && rr <= r ) addv ( data[now], data[now] ), addv ( mult[now], mult[now] ), addv ( addt[now], addt[now] );
		else if ( rr < l || ll > r ) return;
		else {
			int mid = ( ll + rr ) >> 1;
			downtag ( now, rr - ll + 1 );
			mul2 ( l, r, now << 1, ll, mid );
			mul2 ( l, r, now << 1 | 1, mid + 1, rr );
			data[now] = add ( data[now << 1], data[now << 1 | 1] );
		}
	}

	int query ( int l, int r, int now = 1, int ll = 1, int rr = MAX )
	{
		if ( ll >= l && rr <= r ) return data[now];
		else if ( rr < l || ll > r ) return 0;
		else {
			int mid = ( ll + rr ) >> 1;
			downtag ( now, rr - ll + 1 );
			return add ( query ( l, r, now << 1, ll, mid ), query ( l, r, now << 1 | 1, mid + 1, rr ) );
		}
	}

private:
	void downtag ( int now, int size )
	{
		if ( mult[now] ^ 1 ) {
			data[now << 1] = SC ( LL, data[now << 1] ) * mult[now] % MOD;
			data[now << 1 | 1] = SC ( LL, data[now << 1 | 1] ) * mult[now] % MOD;
			mult[now << 1] = SC ( LL, mult[now << 1] ) * mult[now] % MOD;
			mult[now << 1 | 1] = SC ( LL, mult[now << 1 | 1] ) * mult[now] % MOD;
			addt[now << 1] = SC ( LL, addt[now << 1] ) * mult[now] % MOD;
			addt[now << 1 | 1] = SC ( LL, addt[now << 1 | 1] ) * mult[now] % MOD;
			mult[now] = 1;
		}
		if ( addt[now] ) {
			int tmp = SC ( LL, addt[now] ) * ( size >> 1 ) % MOD;
			addv ( data[now << 1], tmp );
			addv ( data[now << 1 | 1], tmp );
			addv ( addt[now << 1], addt[now] );
			addv ( addt[now << 1 | 1], addt[now] );
			addt[now] = 0;
		}
	}

	int data[MAXS];
	int addt[MAXS], mult[MAXS];
}st;

int n, q;
int qtp, qa, qb, qc;
set < PII > s[MAXN];

void init ();
void input ();
void inputq ();
void work ();

void upd ( int l, int r, int x );



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

	scanf ( "%d%d", &n, &q );
}

void inputq ()
{
	// input query

	scanf ( "%d%d%d", &qtp, &qa, &qb );
	if ( qtp == 1 ) scanf ( "%d", &qc );
}

void work ()
{
	// main work

	lp ( _q, 0, q ) {
		inputq ();

		if ( qtp == 1 ) upd ( qa, qb, qc );
		else printf ( "%d\n", st.query ( qa, qb ) );
	}
}



void upd ( int l, int r, int x )
{
	if ( s[x].empty () ) {
		s[x].insert ( MP ( l, r ) );
		st.add1 ( l, r );
		return;
	}

	set < PII > ::iterator il = s[x].upper_bound ( MP ( l, INF ) );
	if ( il != s[x].begin () ) {
		--il;
		if ( il->first < l && il->second >= l ) {
			s[x].insert ( MP ( il->first, l - 1 ) );
			s[x].insert ( MP ( l, il->second ) );
			s[x].erase ( il );
		}
	}
	
	set < PII > ::iterator ir = s[x].upper_bound ( MP ( r, INF ) );
	if ( ir != s[x].begin () ) {
		--ir;
		if ( ir->second > r ) {
			s[x].insert ( MP ( ir->first, r ) );
			s[x].insert ( MP ( r + 1, ir->second ) );
			s[x].erase ( ir );
		}
	}

	int np = l;
	for ( set < PII > ::iterator it = s[x].lower_bound ( MP ( l, 0 ) ), tmp; it != s[x].end () && it->first <= r; it = tmp ) {
		st.add1 ( np, it->first - 1 );
		st.mul2 ( it->first, it->second );
		np = it->second + 1;
		tmp = it, ++tmp;
		s[x].erase ( it );
	}
	st.add1 ( np, r );
	
	set < PII > ::iterator tmp;
	int nl = l, nr = r;
	ir = s[x].upper_bound ( MP ( r, INF ) );
	while ( ir != s[x].end () && ir->first == nr + 1 ) {
		nr = ir->second;
		tmp = ir, ++tmp;
		s[x].erase ( ir );
		ir = tmp;
	}
	if ( ir != s[x].begin () ) {
		il = ir, --il;
		while ( il->second == nl - 1 ) {
			nl = il->first;
			if ( il == s[x].begin () ) {
				s[x].erase ( il );
				break;
			}
			tmp = il;
			--tmp;
			s[x].erase ( il );
			il = tmp;
		}
	}

	s[x].insert ( MP ( nl, nr ) );
}