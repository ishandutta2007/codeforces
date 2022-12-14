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
const int MAXS = MAXN * 4;
const int MAX = 131072;

int n, p, tp;
int x[MAXN];

class stT
{
public:
	stT ()
	{
		init ();
	}

	void init ()
	{
		INIT ( maxi, 0 );
		INIT ( tag, 0 );
	}

	void upd ( int l, int r, int del, int now = 1, int ll = 1, int rr = MAX )
	{
		if ( ll >= l && rr <= r ){
			maxi[now] += del;
			tag[now] += del;
		}else if ( r < ll || l > rr ) return;
		else{
			int mid = ( ll + rr ) >> 1;
			downtag ( now );
			upd ( l, r, del, now<<1, ll, mid );
			upd ( l, r, del, now<<1|1, mid+1, rr );
			maxi[now] = qmax ( maxi[now<<1], maxi[now<<1|1] );
		}
	}

	int query ( int now = 1, int ll = 1, int rr = MAX )
	{
		if ( ll == rr ) return x[ll];
		else{
			int mid = ( ll + rr ) >> 1;
			downtag ( now );
			if ( maxi[now<<1|1] > 0 ) return query ( now<<1|1, mid+1, rr );
			else if ( maxi[now<<1] > 0 ) return query ( now<<1, ll, mid );
			else return -1;
		}
	}

private:
	void downtag ( int now )
	{
		if ( tag[now] ){
			maxi[now<<1] += tag[now];
			tag[now<<1] += tag[now];
			maxi[now<<1|1] += tag[now];
			tag[now<<1|1] += tag[now];
			tag[now] = 0;
		}
	}

	int maxi[MAXS], tag[MAXS];
}st;

void init ();
void input ();
void inputq ();
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

	scanf ( "%d", &n );
}

void inputq ()
{
	// input query

	scanf ( "%d%d", &p, &tp );
	if ( tp == 1 ) scanf ( "%d", &x[p] );
}

void work ()
{
	// main work

	lp ( _q, 0, n ){
		inputq ();
		st.upd ( 1, p, ( tp == 1 ) ? 1 : -1 );
		printf ( "%d\n", st.query () );
	}
}