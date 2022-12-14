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

struct eT
{
	void setd ( int _u, int _v )
	{
		u = _u, v = _v;
	}

	int u, v;
}edge[MAXN];

int n, m;
int ke;

void init ();
void input ();
void work ();

void addedge ( int u, int v );



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
}

void work ()
{
	// main work

	ke = 0;

	int tn = n - 1;
	int in = tn - m, out = m;
	int ans = 0;

	if ( in <= out ){
		int co = n;
		if ( !in ){
			ans = 2;
			lpi ( i, 2, n ) addedge ( 1, i );
		} else{
			if ( in == 1 ){
				addedge ( 1, n );
				--co;
				--out;
				ans = 3;
			} else ans = 4;

			lpi ( i, 1, in ) addedge ( i+1, co-- ), --out;
			while ( out ) addedge ( 2, co-- ), --out;
			lpi ( i, 1, in ) addedge ( 1, i+1 );
		}
	} else{
		int ci = 2;
		lpi ( i, 1, out ) addedge ( 1, ci++ ), --in;
		ans += 2;
		while ( in >= out ){
			lpi ( i, 1, out ) addedge ( ci, ci-out ), ++ci, --in;
			ans += 2;
		}
		if ( in == 1 ) ++ans;
		else if ( in >= 2 ) ans += 2;
		while ( in ) addedge ( ci, ci-out ), ++ci, --in;
		int co = n;
		lpi ( i, 1, out ) addedge ( co, co-out ), --co;
		ans += 2;
	}

	printf ( "%d\n", ans );
	lpi ( i, 1, ke ) printf ( "%d %d\n", edge[i].u, edge[i].v );
}



void addedge ( int u, int v )
{
	edge[++ke].setd ( u, v );
}