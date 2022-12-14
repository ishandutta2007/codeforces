#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
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
const int MAXN = 1007;
const int MAXM = 10007;

struct qT
{
	qT () {}

	qT ( int _id, LL _w )
		: id ( _id ), w ( _w )
	{}

	bool operator < ( const qT &a ) const
	{
		return ( ( w ^ a.w ) ? ( w > a.w ) : ( id < a.id ) );
	}

	int id;
	LL w;
}qt;

struct eT
{
	int u, v, w, last;
}edge[MAXM*2];

int n, m, L, s, t, pos, sum = 0;
bool is0[MAXM];
bool vis[MAXN];
LL st[MAXN];
int la[MAXN];

void init ();
void input ();
void work ();

LL dijkstra ();
bool check1 ( int tst );
bool check2 ( int tst );
void output ();



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

	cin >> n >> m >> L >> s >> t;

	memset ( la, -1, sizeof ( la ) );
	int u, v, w;
	lp ( i, 0, m ){
		cin >> u >> v >> w;
		is0[i] = ( !w );
		if ( is0[i] ) ++sum;
		edge[2*i].u = u, edge[2*i].v = v, edge[2*i].w = w, edge[2*i].last = la[u];
		la[u] = 2*i;
		edge[2*i^1].u = v, edge[2*i^1].v = u, edge[2*i^1].w = w, edge[2*i^1].last = la[v];
		la[v] = 2*i^1;
	}
}

void work ()
{
	// main work

	lp ( i, 0, 2*m ) if ( is0[i>>1] ) edge[i].w = INF;

	LL dist = dijkstra();

	if ( dist < L ){
		cout << "NO" << endl;
		return;
	}else if ( dist == L ){
		output ();
		return;
	}

	lp ( i, 0, 2*m ) if ( is0[i>>1] ) edge[i].w = 1;

	dist = dijkstra ();

	if ( dist > L ){
		cout << "NO" << endl;
		return;
	}

	lp ( i, 0, 2*m ) if ( is0[i>>1] ) edge[i].w = INF;

	int l = 1, r = sum, mid;
	while ( l < r ){
		mid = ( l + r ) / 2;
		if ( check1 ( mid ) )
			r = mid;
		else
			l = mid + 1;
	}

	int t = 0;
	lp ( i, 0, m ){
		if ( is0[i] ){
			++t;
			if ( t == l ){
				t = i;
				break;
			}
		}
	}

	pos = t;

//	pos = l;
	l = 1, r = INF;
	while ( l < r ){
		mid = ( l + r + 1 ) / 2;
		if ( check2 ( mid ) )
			l = mid;
		else
			r = mid - 1;
	}

	edge[2*pos].w = edge[2*pos^1].w = l;

	output ();
}



LL dijkstra ()
{
	priority_queue < qT > q;

	lp ( i, 0, n ) st[i] = LINF;
	memset ( vis, false, sizeof ( vis ) );
	q.push ( qT ( s, 0 ) );
	st[s] = 0;
	while ( !q.empty() ){
		qt = q.top();
		q.pop();

		if ( vis[qt.id] ) continue;
		if ( qt.id == t ) break;
		vis[qt.id] = true;

		for ( int i = la[qt.id]; i ^ -1; i = edge[i].last ){
			if ( st[edge[i].v] > st[qt.id] + edge[i].w ){
				st[edge[i].v] = st[qt.id] + edge[i].w;
				q.push ( qT ( edge[i].v, st[edge[i].v] ) );
			}
		}
	}

	return st[t];
}

bool check1 ( int tst )
{
	int t = 0;
	lpi ( i, 0, m ){
		if ( is0[i] ){
			edge[2*i].w = edge[2*i^1].w = 1, ++t;
			if ( t == tst ){
				t = i;
				break;
			}
		}
	}
	lp ( i, t+1, m )
		if ( is0[i] ) edge[2*i].w = edge[2*i^1].w = INF;

	return ( dijkstra() <= L );
}

bool check2 ( int tst )
{
	edge[2*pos].w = edge[2*pos^1].w = tst;
	return ( dijkstra() <= L );
}

void output ()
{
	cout << "YES" << endl;
	lp ( i, 0, m ){
		cout << edge[2*i].u << " " << edge[2*i].v << " " << edge[2*i].w << endl;
	}
}