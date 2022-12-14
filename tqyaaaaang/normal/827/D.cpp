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
const int MINF = 0x3f3f3f3f;
const int MAXN = 410007;

class lctT
{
public:
	lctT ()
	{
		INIT ( nd, -1 );
		INIT ( data, -1 );
		INIT ( amin, MINF );
		INIT ( mtag, MINF );
	}

	int link ( int u, int v, int e, int x )
	{
		if ( !iscon ( u, v ) ) return _link ( u, v, e, x ), -1;
		else{
			upd ( u, v, x - 1 );
			return query ( u, v ) - 1;
		}
	}

	void _link ( int u, int v, int e, int x )
	{
		link ( u, e );
		link ( v, e );
		eu[e] = u, ev[e] = v;
		upd ( e, x );
	}

	void link ( int u, int v )
	{
		croot ( u );
		access ( v );
		fa[u] = v;
		access ( u );
	}

	void cut ( int e )
	{
		if ( eu[e] ){
			cut ( e, eu[e] );
			cut ( e, ev[e] );
			eu[e] = ev[e] = 0;
		}
	}

	void cut ( int u, int v )
	{
		croot ( u );
		access ( v );
		ch[v][0] = fa[u] = 0;
		upd ( v );
	}

	void upd ( int now, int x )
	{
		croot ( now );
		nd[now] = x;
		upd ( now );
	}

	void upd ( int u, int v, int x )
	{
		croot ( u );
		access ( v );
		mtag[v] = qmin ( mtag[v], x );
		amin[v] = qmin ( amin[v], x );
	}

	int query ( int now )
	{
		access ( now );
		return amin[now];
	}

	int query ( int u, int v )
	{
		croot ( u );
		access ( v );
		return data[v];
	}

private:
	void rot ( int now )
	{
		int nf = fa[now], np = fa[nf], d = ch[nf][1] == now;

		fa[now] = np;
		if ( !isroot ( nf ) ) ch[np][ch[np][1]==nf] = now;
		fa[ch[now][d^1]] = nf, ch[nf][d] = ch[now][d^1];
		fa[nf] = now, ch[now][d^1] = nf;

		upd ( nf ), upd ( now );
	}

	void splay ( int now )
	{
		rev_push ( now );
		int nf, np;
		while ( !isroot ( now ) ){
			nf = fa[now], np = fa[nf];
			if ( !isroot ( nf ) ) rot ( ( ( ch[nf][0] == now ) == ( ch[np][0] == nf ) ) ? nf : now );
			rot ( now );
		}
	}

	void access ( int now )
	{
		int v = 0, tn = now;
		while ( now ){
			splay ( now );
			ch[now][1] = v;
			upd ( now );
			v = now, now = fa[now];
		}
		splay ( tn );
	}

	void croot ( int now )
	{
		access ( now );
		rev[now] ^= 1;
	}

	int getroot ( int now )
	{
		while ( ch[now][0] ) now = ch[now][0];
		splay ( now );
		return now;
	}

	bool iscon ( int u, int v )
	{
		croot ( u );
		access ( v );
		return getroot ( v ) == u;
	}

	bool isroot ( int now )
	{
		return ( !( fa[now] && ( ( ch[fa[now]][0] == now ) || ( ch[fa[now]][1] == now ) ) ) );
	}

	void push_down ( int now )
	{
		if ( rev[now] ){
			rev[ch[now][0]] ^= 1, rev[ch[now][1]] ^= 1;
			swap ( ch[now][0], ch[now][1] );
			rev[now] = 0;
		}

		if ( mtag[now] ^ MINF ){
			amin[ch[now][0]] = qmin ( amin[ch[now][0]], mtag[now] );
			mtag[ch[now][0]] = qmin ( mtag[ch[now][0]], mtag[now] );
			amin[ch[now][1]] = qmin ( amin[ch[now][1]], mtag[now] );
			mtag[ch[now][1]] = qmin ( mtag[ch[now][1]], mtag[now] );
			mtag[now] = MINF;
		}
	}

	void rev_push ( int now )
	{
		if ( !isroot ( now ) ) rev_push ( fa[now] );
		push_down ( now );
	}

	void upd ( int now )
	{
		data[now] = max ( qmax ( data[ch[now][0]], data[ch[now][1]] ), nd[now] );
	}

	int fa[MAXN], ch[MAXN][2], eu[MAXN], ev[MAXN];
	bool rev[MAXN];
	int nd[MAXN], data[MAXN];
	int amin[MAXN], mtag[MAXN];
}lct;

struct eT
{
	bool operator < ( const eT &a ) const
	{
		return w < a.w;
	}

	int id, u, v, w, ans;
	bool inl;
}e[MAXN];

int n, m;
int ans[MAXN];

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

	scanf ( "%d%d", &n, &m );
	lpi ( i, 1, m ) scanf ( "%d%d%d", &e[i].u, &e[i].v, &e[i].w ), e[i].id = i;
}

void work ()
{
	// main work

	sort ( e+1, e+1+m );

	int ret;
	lpi ( i, 1, m ){
		ret = lct.link ( e[i].u, e[i].v, i+n+3, e[i].w );
		if ( ~ret ){
			e[i].ans = ret;
		} else e[i].inl = true;
	}
	lpi ( i, 1, m ){
		if ( e[i].inl ) e[i].ans = lct.query ( i+n+3 );
	}

	lpi ( i, 1, m ) ans[e[i].id] = e[i].ans;
	lpi ( i, 1, m ) printf ( "%d ", ( ans[i] ^ MINF ) ? ans[i] : -1 );
	putchar ( '\n' );
}