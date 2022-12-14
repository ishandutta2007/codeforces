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
#define ULL unsigned long long

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 300007;
const ULL BASE = 469762049;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];

int n, m;
int ke, la[MAXN];
int inb[MAXN];
int c[MAXN];
map < ULL, int > mp;
map < ULL, int > ::iterator it;
AR( int ) ta[MAXN];
AR( int ) e[MAXN];
int kd;

void init ();
void input ();
void work ();

ULL gethsh ( AR( int ) &ar );
void dfs ( int now, int fa );



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
	int u, v;
	ke = 0;
	INIT ( la, -1 );
	lp ( i, 0, m ){
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

	ULL hv;
	int kv = 0;
	lpi ( i, 1, n ){
		ta[i].push_back ( i );
		for ( int j = la[i]; ~j; j = edge[j].last ) ta[i].push_back ( edge[j].v );
		hv = gethsh ( ta[i] );
		if ( ( it = mp.find ( hv ) ) != mp.end () ) inb[i] = it->second;
		else mp.insert ( MP ( hv, ++kv ) ), inb[i] = kv;
	}

	lpi ( i, 1, n ){
		for ( int j = la[i]; ~j; j = edge[j].last ){
			if ( inb[i] ^ inb[edge[j].v] ) e[inb[i]].push_back ( inb[edge[j].v] );
		}
	}

	lpi ( i, 1, kv ){
		sort ( e[i].begin (), e[i].end () );
		e[i].erase ( unique ( e[i].begin (), e[i].end () ), e[i].end () );
	}

	lpi ( i, 1, n ){
		if ( e[i].size () > 2 ){
			printf ( "NO\n" );
			return;
		}
	}

	kd = 0;
	if ( kv == 1 ) c[1] = 1;
	else{
		lpi ( i, 1, kv ){
			if ( e[i].size () == 1 ){
				dfs ( i, -1 );
				break;
			}
		}
	}

	printf ( "YES\n" );
	lpi ( i, 1, n ) printf ( "%d ", c[inb[i]] );
	putchar ( '\n' );
}



ULL gethsh ( AR( int ) &ar )
{
	sort ( ar.begin (), ar.end () );
	ULL hv = 0;
	int size = ar.size ();
	lp ( i, 0, size ) hv = hv * BASE + ar[i];
	return hv;
}

void dfs ( int now, int fa )
{
	c[now] = ++kd;
	for ( auto x : e[now] ) if ( x ^ fa ) dfs ( x, now );
}