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

#define I(a,b) ((a)*3+(b))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 11;
const int MAXS = ( ( 1 << 8 ) + 7 ) * 3;

struct eT
{
	void setd ( int _u1, int _u2, int _v, int _w, int _t, int _l )
	{
		u1 = _u1, u2 = _u2, v = _v, w = _w, tp = _t, last = _l;
	}

	int u1, u2, v, w, last;
	int tp;
}edge[MAXS*MAXS*15];

struct qT
{
	qT () : id ( 0 ), dist ( 0 ), md ( "" ) {}
	qT ( int _i, int _d, string &_md ) : id ( _i ), dist ( _d ), md ( _md ) {}

	bool operator < ( const qT &a ) const
	{
		return ( dist ^ a.dist ) ? ( dist > a.dist ) : ( md > a.md );
	}

	int id, dist;
	string md;
};

int n = 8, T;
int ke, la[MAXS];
char s[MAXN];
int dist[MAXS];
string md[MAXS];
bool vis[MAXS];

void init ();
void input ();
void work ();

void adde1 ( int u, int v, int w, int t )
{
	edge[ke].setd ( u, 0, v, w, t, la[u] );
	la[u] = ke++;
}

void adde2 ( int u1, int u2, int v, int w, int t )
{
	edge[ke].setd ( u1, u2, v, w, t, la[u1] );
	la[u1] = ke++;
	edge[ke].setd ( u2, u1, v, w, t, la[u2] );
	la[u2] = ke++;
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

	scanf ( "%d", &T );
}

void work ()
{
	// main work

	ke = 0;
	INIT ( la, -1 );

	int ms = ( 1 << n );
	lp ( i, 0, ms ) {
		adde1 ( I ( i, 2 ), I ( ( ms - 1 ) ^ i, 2 ), 1, 2 );
		lp ( j, 0, 2 ) adde1 ( I ( i, j ), I ( i, 2 ), 2, 3 );
		lp ( j, 0, 2 ) adde1 ( I ( i, j + 1 ), I ( i, j ), 0, 4 );
		lp ( j, 0, ms ) {
			adde2 ( I ( i, 1 ), I ( j, 1 ), I ( i & j, 1 ), 1, 1 );
			adde2 ( I ( i, 0 ), I ( j, 0 ), I ( i | j, 0 ), 1, 0 );
		}
	}

	priority_queue < qT > pq;
	INIT ( dist, 0x3f3f3f3f );
	fill ( md, md + MAXS, string ( "{" ) );
	lp ( i, 0, 3 ) {
		int tmp = 0;
		lp ( j, 0, 8 ) {
			if ( j >> ( 3 - i - 1 ) & 1 ) tmp |= 1 << j;
		}
		lp ( j, 0, 3 ) {
			dist[I(tmp,j)] = 1, md[I(tmp,j)] = string ( "" ) + SC ( char, 'x' + i );
			pq.push ( qT ( I ( tmp, j ), 1, md[I ( tmp, j )] ) );
		}
	}

	int now, v, td, u2;
	string tm;
	while ( !pq.empty () ) {
		now = pq.top ().id; pq.pop ();
		if ( vis[now] ) continue;
		vis[now] = true;
		for ( int i = la[now]; ~i; i = edge[i].last ) {
//			cerr << now << " " << i << endl;
			v = edge[i].v;
			if ( edge[i].tp <= 1 && !vis[edge[i].u2] ) continue;
			td = ( ( edge[i].tp <= 1 ) ? ( dist[now] + dist[edge[i].u2] ) : dist[now] ) + edge[i].w;
			if ( edge[i].tp == 0 ) tm = min ( md[now] + "|" + md[edge[i].u2], md[edge[i].u2] + "|" + md[now] );
			else if ( edge[i].tp == 1 ) tm = min ( md[now] + "&" + md[edge[i].u2], md[edge[i].u2] + "&" + md[now] );
			else if ( edge[i].tp == 2 ) tm = "!" + md[now];
			else if ( edge[i].tp == 3 ) tm = "(" + md[now] + ")";
			else tm = md[now];
			if ( ( td ^ dist[v] ) ? ( td < dist[v] ) : ( tm < md[v] ) ) {
				dist[v] = td;
				md[v] = tm;
				pq.push ( qT ( v, td, tm ) );
			}
		}
	}

	//lp ( i, 0, ms ) {
	//	string ns;
	//	lp ( j, 0, n ) ns += '0' + ( i >> j & 1 );
	//	cerr << i << " " << ns << " " << dist[I ( i, 0 )] << " " << md[I( i, 0 )] << endl;
	//}

	int cv;
	lp ( i, 0, T ) {
		scanf ( "%s", s );
		cv = 0;
		lp ( i, 0, n ) if ( s[i] == '1' ) cv |= 1 << i;
		cout << md[I ( cv, 0 )] << endl;
	}
}