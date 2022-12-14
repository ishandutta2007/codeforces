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
/*
class st1T
{
public:
	st1T ()
	{
//		INIT ( data, 0x3f3f3f3f );
//		INIT ( tag, -1 );
		fill ( data, data+MAXS, LINF );
		fill ( tag, tag+MAXS, LINF );
	}

	void upd ( int l, int r, int x, int now = 1, int ll = 1, int rr = MAX )
	{
		if ( ll >= l && rr <= r ) 
	}

private:
	void downtag ( int now )
	{
		if ( ~tag[now] ){
			tag[now<<1] = qmin ( tag[now<<1], tag[now] );
			tag[now<<1|1] = qmin ( tag[now<<1|1], tag[now] );
			data[now<<1] = qmin ( data[now<<1], tag[now] );
			data[now<<1|1] = qmin ( data[now<<1|1], tag[now] );
			tag[now] = -1;
		}
	}

	LL data[MAXN], tag[MAXN];
}st1;*/

class stT
{
public:
	void upd ( int l, int r, int x, int now = 1, int ll = 1, int rr = MAX )
	{
		if ( ll >= l && rr <= r ) ar[now].push_back ( x );
		else if ( rr < l || ll > r ) return;
		else{
			int mid = ( ll + rr ) >> 1;
			upd ( l, r, x, now<<1, ll, mid );
			upd ( l, r, x, now<<1|1, mid+1, rr );
		}
	}

	AR( int ) query ( int p )
	{
		p += MAX - 1;

		AR( int ) ans;
		for ( ; p; p >>= 1 ){
			for ( auto x : ar[p] ){
				if ( !vis[x] ){
					vis[x] = true;
					ans.push_back ( x );
				}
			}
			ar[p].clear ();
		}

		return ans;
	}

private:
	bool vis[MAXN];
	AR( int ) ar[MAXS];
}st;

struct qT
{
	qT () {}
	qT ( int _l, int _r, LL _d ) : l ( _l ), r ( _r ), dist ( _d ) {}

	bool operator < ( const qT &a ) const
	{
		return dist > a.dist;
	}

	int l, r;
	LL dist;
};

struct eT
{
	void setd ( int _u, int _v, int _l, int _r, int _w, int _tp, int _la )
	{
		u = _u, v = _v, l = _l, r = _r, w = _w, tp = _tp, last = _la;
	}

	int u, v, l, r, w, tp, last;
}edge[MAXN];

int n, m, S;
int ke, la[MAXN];
LL dist[MAXN];
bool vis[MAXN];
set < int > lt;

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

	scanf ( "%d%d%d", &n, &m, &S );
	ke = 0;
	INIT ( la, -1 );
	int tp, u, v, l, r, w;
	lp ( i, 0, m ){
		scanf ( "%d", &tp );
		if ( tp == 1 ){
			scanf ( "%d%d%d", &u, &v, &w );
			edge[ke].setd ( u, v, 0, 0, w, 1, la[u] );
			la[u] = ke++;
		} else{
			scanf ( "%d%d%d%d", &u, &l, &r, &w );
			if ( tp == 2 ){
				edge[ke].setd ( u, 0, l, r, w, 2, la[u] );
				la[u] = ke++;
			} else{
				edge[ke].setd ( 0, u, l, r, w, 3, -1 );
				st.upd ( l, r, ke );
				++ke;
			}
		}
	}
}

void work ()
{
	// main work

	lpi ( i, 0, n+1 ) lt.insert ( i );

	fill ( dist, dist+MAXN, LINF );
	priority_queue < qT > pq;
	pq.push ( qT ( S, S, 0 ) );
	dist[S] = 0;
	int nl, nr, now, v;
	set < int > ::iterator il, ir, ti;
	AR( int ) na;
	LL nd;
	qT tmp;
	while ( !pq.empty () ){
		tmp = pq.top (); pq.pop ();
		nl = tmp.l, nr = tmp.r, nd = tmp.dist;
		il = lt.lower_bound ( nl ), ir = lt.upper_bound ( nr );
//		--ir;
		for ( set < int > ::iterator it = il; it != ir; ){
			now = *it;
			if ( vis[now] ) continue;
			vis[now] = true;
			ti = it; ++it;
			lt.erase ( ti );
			dist[now] = nd;
			for ( int i = la[now]; ~i; i = edge[i].last ){
				if ( edge[i].tp == 1 ) pq.push ( qT ( edge[i].v, edge[i].v, nd + edge[i].w ) );
				else pq.push ( qT ( edge[i].l, edge[i].r, nd + edge[i].w ) );
			}
			na = st.query ( now );
			for ( auto x : na ){
				pq.push ( qT ( edge[x].v, edge[x].v, nd + edge[x].w ) );
			}
		}
	}

	lpi ( i, 1, n ) printf ( "%I64d ", ( dist[i] ^ LINF ) ? dist[i] : -1 );
	putchar ( '\n' );
}