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
const int MAXN = 300007;
const int MAXL = 31;
const int MAXS = 10000007;

int n;
int a[MAXN];
int p[MAXN];
int kc;
int ch[MAXS][2];
int sz[MAXS];
int stk[MAXL], top;

void init ();
void input ();
void work ();

void addtrie ( int x )
{
	int now = 1, nv;
	lpdi ( i, MAXL - 1, 0 ) {
		nv = x >> i & 1;
		++sz[now];
		if ( ch[now][nv] ) now = ch[now][nv];
		else now = ch[now][nv] = ++kc;
	}
	++sz[now];
}

int query ( int x )
{
	int now = 1, nv, ans = 0;
	lpdi ( i, MAXL - 1, 0 ) {
		nv = x >> i & 1;
		--sz[now];
		if ( ch[now][nv] && sz[ch[now][nv]] ) now = ch[now][nv], ans |= nv << i;
		else now = ch[now][nv ^ 1], ans |= ( nv ^ 1 ) << i;
	}
	--sz[now];
	return ans;
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
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
	lpi ( i, 1, n ) scanf ( "%d", &p[i] );
}

void work ()
{
	// main work

	kc = 1;
	lpi ( i, 1, n ) addtrie ( p[i] );
	lpi ( i, 1, n ) printf ( "%d ", a[i] ^ query ( a[i] ) );
	putchar ( '\n' );
}