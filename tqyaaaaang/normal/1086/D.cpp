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

int CID[257];

const int WIN[3][3] = {
	1, 0, 1,
	1, 1, 0,
	0, 1, 1
};

const int LOSE[8] = { -1, 2, 0, 0, 1, 2, 1, -1 };

class ftT
{
public:
	void upd ( int p, int x )
	{
		for ( ; p < MAXN; p += p & -p ) data[p] += x;
	}

	int sum ( int p )
	{
		int ans = 0;
		for ( ; p; p ^= p & -p ) ans += data[p];
		return ans;
	}

	int query ( int l, int r )
	{
		return sum ( r ) - sum ( l - 1 );
	}

private:
	int data[MAXN];
}ft[3];

int n, q;
char is[MAXN];
int a[MAXN];
set < int > s[3];
int pl[3], pr[3];
int ar[23], ka;
int qi, qx;

void init ();
void input ();
void inputq ();
void work ();

int getans ();



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

	CID['R'] = 0;
	CID['P'] = 1;
	CID['S'] = 2;
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &q );
	scanf ( "%s", is );
}

void inputq ()
{
	// input query

	char tqs[5];
	scanf ( "%d%s", &qi, &tqs );
	qx = CID[tqs[0]];
}

void work ()
{
	// main work

	lpi ( i, 1, n ) {
		a[i] = CID[is[i - 1]];
		ft[a[i]].upd ( i, 1 );
		s[a[i]].insert ( i );
	}

	printf ( "%d\n", getans () );
	lp ( _q, 0, q ) {
		inputq ();

		ft[a[qi]].upd ( qi, -1 );
		s[a[qi]].erase ( qi );
		a[qi] = qx;
		ft[a[qi]].upd ( qi, 1 );
		s[a[qi]].insert ( qi );

		printf ( "%d\n", getans () );
	}
}



int getans ()
{
	ka = 0;
	lp ( i, 0, 3 ) {
		if ( s[i].empty () ) pl[i] = INF, pr[i] = -1;
		else {
			pl[i] = *s[i].begin (), pr[i] = *s[i].rbegin ();
			ar[++ka] = pl[i] + 1, ar[++ka] = pr[i];
		}
	}
	ar[++ka] = 1, ar[++ka] = n + 1;

	sort ( ar + 1, ar + 1 + ka );

	int stl, str;
	int res[5], kr;
	int ans = 0;
	lp ( i, 1, ka ) {
		if ( ar[i] == ar[i + 1] ) continue;
		stl = str = 0;
		lp ( j, 0, 3 ) {
			if ( ar[i] > pl[j] ) stl |= 1 << j;
			if ( ar[i] < pr[j] ) str |= 1 << j;
		}
		kr = 0;
		if ( ~LOSE[stl] ) res[++kr] = LOSE[stl];
		if ( ~LOSE[str] ) res[++kr] = LOSE[str];
		if ( kr == 2 && res[1] == res[2] ) --kr;
		lpi ( j, 1, kr ) ans += ft[res[j]].query ( ar[i], ar[i + 1] - 1 );
	}

	return n - ans;
}