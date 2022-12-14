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
const int MOD = 1e9 + 7;

int a, b, h;
LL frac[MAXN];

void init ();
void input ();
void work ();

LL qpow ( LL a, LL b )
{
	LL base = a, ans = 1;
	while ( b ){
		if ( b & 1 ) ans = ( ans * base ) % MOD;
		base = ( base * base ) % MOD;
		b >>= 1;
	}
	return ans;
}

LL getC ( int a, int b )
{
	if ( a < b || b < 0 ) return 0;
	return ( ( ( frac[a] * qpow ( frac[b], MOD-2 ) ) % MOD ) * qpow ( frac[a-b], MOD-2 ) ) % MOD;
}

LL getnum ( int b, int a )
{
//	if ( !a ) return 1;
	return getC ( a + b - 1, b - 1 );
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

	frac[0] = 1;
	lp ( i, 1, MAXN ) frac[i] = ( frac[i-1] * i ) % MOD;

//	cout << qpow ( 999949972, MOD-2 ) << endl;
}

void input ()
{
	// input method

	scanf ( "%d%d%d", &a, &b, &h );
}

void work ()
{
	// main work

	// a == 0 and b == 0

	if ( b == 0 ){
		cout << 1 << endl;
		return;
	}else if ( a == 0 ){
		if ( b <= h ) cout << 0 << endl;
		else cout << 1 << endl;
		return;
	}

	LL p = 0, q = 0;
	int la = a - 1, lb = b - 1, ca = 1, cb = 1;
	while ( la >= 0 && lb >= 0 ){
//		if ( la >= 0 ) q += qpow ( la, ca ) * qpow ( lb, cb ) * 2;
//		if ( lb >= 0 ) q += qpow ( lb, cb );
//		q += ( qpow ( ca, la ) * qpow ( cb, lb ) * 2 ) % MOD;
//		if ( la ) q += ( qpow ( ca+1, la-1 ) * qpow ( cb, lb ) ) % MOD;
//		if ( lb ) q += ( qpow ( cb+1, lb-1 ) * qpow ( ca, la ) ) % MOD;
		q += ( getnum ( ca, la ) * getnum ( cb, lb ) * 2 ) % MOD;
		if ( la ) q += ( getnum ( ca+1, la-1 ) * getnum ( cb, lb ) ) % MOD;
		if ( lb ) q += ( getnum ( cb+1, lb-1 ) * getnum ( ca, la ) ) % MOD;
		q %= MOD;
		++ca, ++cb, --la, --lb;
	}

	la = a - 1, lb = b - h - 1, ca = 1, cb = 1;
	while ( la >= 0 && lb >= 0 ){
//		if ( la >= 0 ) p += qpow ( la, ca ) * qpow ( lb, cb ) * 2;
//		if ( lb >= 0 ) p += qpow ( lb, cb );
//		p += ( qpow ( ca, la ) * qpow ( cb, lb ) * 2 ) % MOD;
//		if ( la ) p += ( qpow ( ca+1, la-1 ) * qpow ( cb, lb ) ) % MOD;
//		if ( lb > h ) p += ( qpow ( cb+1, lb-h-1 ) * qpow ( ca, la ) ) % MOD;
		p += ( getnum ( ca, la ) * getnum ( cb, lb ) * 2 ) % MOD;
		if ( la ) p += ( getnum ( ca+1, la-1 ) * getnum ( cb, lb ) ) % MOD;
		if ( lb ) p += ( getnum ( cb+1, lb-h-1 ) * getnum ( ca, la ) ) % MOD;
		p %= MOD;
		++ca, ++cb, --la, lb -= h + 1;
	}

	printf ( "%I64d\n", ( p * qpow ( q, MOD-2 ) ) % MOD );
}