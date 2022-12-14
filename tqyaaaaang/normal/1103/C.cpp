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
const int MAXN = 250007;
const int MAXM = 1000007;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXM];

int n, m, K, rk;
int ke, la[MAXN];
int stk[MAXN], top;
bool vis[MAXN];
int upe[MAXN];
int fa[MAXN], lev[MAXN];
AR ( AR ( int ) ) ans;

void init ();
void input ();
void work ();

int dfs ( int now, int nf, int nl );
void getlink ( int u, int v, AR ( int ) &ans );
void merge ( AR ( int ) &a, AR ( int ) &b );



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

	scanf ( "%d%d%d", &n, &m, &K );
	INIT ( la, -1 );
	int u, v;
	lp ( i, 0, m ) {
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

	rk = ( n + K - 1 ) / K;
	
	lev[1] = 0;
	vis[1] = true;
	stk[++top] = 1;
	int ret;
	for ( int i = la[1]; ~i; i = edge[i].last ) {
		if ( !vis[edge[i].v] ) {
			dfs ( edge[i].v, 1, 1 );
		}
	}

	printf ( "CYCLES\n" );
	int size = K;
	lp ( i, 0, size ) {
		printf ( "%d\n", ans[i].size () );
		for ( auto x : ans[i] ) printf ( "%d ", x );
		putchar ( '\n' );
	}
}



int dfs ( int now, int nf, int nl )
{
	vis[now] = true;
	stk[++top] = now;
	fa[now] = nf;
	lev[now] = nl;
	if ( top > rk ) {
		printf ( "PATH\n%d\n", top );
		lpi ( i, 1, top ) printf ( "%d ", stk[i] );
		putchar ( '\n' );
		exit ( 0 );
	}

	int v, ret;
	int cur[2], kc = 0;
	bool flag = false;
	int okc = -1;
	upe[now] = -1;
	for ( int i = la[now]; ~i; i = edge[i].last ) {
		if ( ( v = edge[i].v ) ^ nf ) {
			if ( !vis[v] ) {
				ret = dfs ( v, now, nl + 1 );
				if ( ret == -1 ) {
					flag = true;
				} else if ( kc < 2 ) {
					cur[kc++] = ret;
				}
			} else {
				if ( ( lev[now] - lev[v] + 1 ) % 3 ) {
					okc = now;
					upe[now] = v;
				} else if ( upe[now] == -1 && kc < 2 ){
					cur[kc++] = now;
					upe[now] = v;
				}
			}
		}
	}
	--top;
	if ( flag ) return -1;
	else if ( ~okc ) {
		AR ( int ) ans;
		getlink ( okc, upe[okc], ans );
		ans.push_back ( upe[okc] );
		::ans.push_back ( ans );
		return -1;
	} else if ( kc <= 1 ) return cur[0];
	else{
		int d1 = cur[0], u1 = upe[d1], d2 = cur[1], u2 = upe[d2];
		AR ( int ) ans, tmp;
		getlink ( d1, now, ans );
		ans.push_back ( now );
		getlink ( d2, now, tmp );
		reverse ( tmp.begin (), tmp.end () );
		merge ( ans, tmp );
		if ( lev[u1] < lev[u2] ) {
			ans.push_back ( u1 );
			getlink ( u2, u1, tmp );
			reverse ( tmp.begin (), tmp.end () );
			merge ( ans, tmp );
		} else {
			ans.push_back ( u2 );
			getlink ( u1, u2, tmp );
			reverse ( tmp.begin (), tmp.end () );
			merge ( ans, tmp );
		}
		::ans.push_back ( ans );
		return -1;
	}
}

void getlink ( int u, int v, AR ( int ) &ans )
{
	ans.clear ();
	for ( ; u ^ v; u = fa[u] ) ans.push_back ( u );
}

void merge ( AR ( int ) &a, AR ( int ) &b )
{
	for ( auto x : b ) a.push_back ( x );
}