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
const int MOD = 1e9 + 7;

struct eT
{
	void setd ( int _u, int  _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];

int n;
int ke, la[MAXN];
bool vis[MAXN];
bool curflag, flag1;

void init ();
void input ();
void work ();

int dfs ( int now, int fa );



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
	int u, v;
	ke = 0;
	INIT ( la, -1 );
	lpi ( i, 1, n ) {
		scanf ( "%d%d", &u, &v );
		edge[ke].setd ( u, v, la[u] );
		la[u] = ke++;
		edge[ke].setd ( v, u, la[v] );
		la[v] = ke++;
	}
}

void work ()
{
	// main work

	n <<= 1;

	LL ans = 1;
	int ns;
	lpi ( i, 1, n ) {
		if ( !vis[i] ) {
			curflag = flag1 = false;
			ns = dfs ( i, -1 );
			if ( flag1 ) ns = 1;
			else if ( curflag ) ns = 2;
			( ans *= ns ) %= MOD;
		}
	}

	cout << ans << endl;
}



int dfs ( int now, int fa )
{
	if ( vis[now] ) {
		curflag = true;
		return 0;
	}
	vis[now] = true;

	int ns = 1;
	for ( int i = la[now]; ~i; i = edge[i].last ) {
		if ( edge[i].v == now ) {
			flag1 = true;
		} else if ( edge[i].v ^ fa ) ns += dfs ( edge[i].v, now );
	}

	return ns;
}