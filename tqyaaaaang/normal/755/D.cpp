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
const int MAXN = 1000017;

class ftT
{
public:
	void upd ( int p, int del )
	{
		p += 5;
		for ( ; p < MAXN; p += p&-p ) data[p] += del;
	}

	int sum ( int p )
	{
		p += 5;
		int ans = 0;
		for ( ; p; p ^= p&-p ) ans += data[p];
		return ans;
	}

private:
	int data[MAXN];
}ft;

int n, k;

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

	scanf ( "%d%d", &n, &k );
}

void work ()
{
	// main work

	if ( k > ( n >> 1 ) ) k = n - k;

	int x = 0, nxt;
	LL ans = 1;
	lp ( i, 0, n ){
		nxt = x + k;
		++ans;
		if ( nxt < n ){
			ans += ft.sum ( nxt - 1 ) - ft.sum ( x );
		}else{
			nxt -= n;
			ans += ( i << 1 ) - ft.sum ( x ) + ft.sum ( nxt - 1 );
		}
		ft.upd ( nxt, 1 ), ft.upd ( x, 1 );
		printf ( "%I64d ", ans );
		x = nxt;
	}
	putchar ( '\n' );
}