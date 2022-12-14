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
const int BASE = 4;
const int MAX = 13;
const int E = 10;
const int MAXQ = 17;
const int SIGMA = 257;

class stT
{
public:
	void setsize ( int size )
	{
		size += 7;
		MAX = 1;
		while ( MAX < size ) MAX <<= 1;
		data.resize ( ( MAX << 1 ) + 1007 );
	}

	void upd ( int p, int x )
	{
		data[p+=MAX-1] = x;
		for ( p >>= 1; p; p >>= 1 ) data[p] = data[p<<1] + data[p<<1|1];
	}

	int sum ( int l, int r )
	{
		if ( l > r ) return 0;
		int ans = 0;
		for ( l += MAX - 2, r += MAX; l ^ r ^ 1; l >>= 1, r >>= 1 ){
			if ( ~l&1 ) ans += data[l^1];
			if ( r&1 ) ans += data[r^1];
		}
		return ans;
	}

private:
	int MAX;
	AR( int ) data;
}st[BASE][MAX][MAX];

char ITC[] = "ATCG";
int CTI[SIGMA];

int n, q;
char s[MAXN];
int tp, a, b;
char qs[MAXQ];

void init ();
void input ();
void inputq ();
void work ();

int getbid ( int bl, int bi, int x );



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

	CTI['A'] = 0, CTI['T'] = 1, CTI['C'] = 2, CTI['G'] = 3;
}

void input ()
{
	// input method

	scanf ( "%s%d", s, &q );
}

void inputq ()
{
	// input query

	scanf ( "%d", &tp );
	if ( tp == 1 ) scanf ( "%d%s", &a, qs );
	else scanf ( "%d%d%s", &a, &b, qs );
}

void work ()
{
	// main work

	n = strlen ( s );

	lp ( c, 0, BASE ){
		lpi ( l, 1, E ){
			lp ( i, 0, l ){
				st[c][l][i].setsize ( n / l + 1 );
				for ( int j = i, ij = 1; j < n; j += l, ++ij ) if ( s[j] == ITC[c] ) st[c][l][i].upd ( ij, 1 );
			}
		}
	}

	int nl, ans, nc;
	lp ( _q, 0, q ){
		inputq ();

		if ( tp == 1 ){
			--a;
			lpi ( l, 1, E ){
				st[CTI[s[a]]][l][a%l].upd ( a/l+1, 0 );
				st[CTI[qs[0]]][l][a%l].upd ( a/l+1, 1 );
			}
			s[a] = qs[0];
		} else{
			nl = strlen ( qs );
			--a, --b;
			ans = 0;
			lp ( i, 0, nl ){
				nc = CTI[qs[(i-(a%nl)+nl)%nl]];
				ans += st[nc][nl][i].sum ( getbid ( nl, i, a-1 ) + 1, getbid ( nl, i, b ) );
			}
			printf ( "%d\n", ans );
		}
	}
}



int getbid ( int bl, int bi, int x )
{
	if ( x < 0 ) return 0;
	int ans = x / bl;
	if ( x % bl >= bi ) ++ans;
	return ans;
}