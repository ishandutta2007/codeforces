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
const int MAXN = 300007;

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
int q[MAXN], lev[MAXN], pre[MAXN];
bool vis[MAXN], v1[MAXN], tv[MAXN];
int t2[MAXN], t22[MAXN];
int deg[MAXN];
int ar[MAXN], ka;
AR ( int ) med;

void init ();
void input ();
void work ();

void dfs ( int now );



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

	scanf ( "%d%d", &n, &m );
	INIT ( la, -1 );
	int u, v;
	lp ( i, 0, m ) {
		scanf ( "%d%d", &u, &v );
		edge[ke].setd ( u, v, la[u] );
		la[u] = ke++;
		edge[ke].setd ( v, u, la[v] );
		la[v] = ke++;
		++deg[u], ++deg[v];
	}
}

void work ()
{
	// main work

	int l = 0, r = 0, now, v;
	q[r++] = 1;
	INIT ( lev, -1 );
	lev[1] = 0;
	while ( l < r ) {
		now = q[l++];
		for ( int i = la[now]; ~i; i = edge[i].last ) {
			if ( lev[v = edge[i].v] == -1 ) {
				lev[v] = lev[now] + 1;
				pre[v] = now;
				q[r++] = v;
			}
		}
	}

	vis[1] = true;
	for ( int i = la[1]; ~i; i = edge[i].last ) v1[edge[i].v] = true;

	int ans = INF;
	if ( ~lev[n] ) {
		for ( int t = n; t; t = pre[t] ) med.push_back ( t );
		reverse ( med.begin (), med.end () );
		ans = lev[n];
	}

	for ( int i = la[1]; ~i; i = edge[i].last ) {
		if ( !vis[v = edge[i].v] ) {
			ka = 0;
			dfs ( v );
			if ( ans > 4 ) {
				lpi ( i, 1, ka ) {
					if ( v1[ar[i]] ) {
						for ( int j = la[ar[i]]; ~j; j = edge[j].last ) if ( edge[j].v ^ 1 ) t2[edge[j].v] = ar[i];
					}
				}
				lpi ( i, 1, ka ) {
					if ( !v1[ar[i]] && t2[ar[i]] ) {
						ans = 4;
						med.clear ();
						med.push_back ( 1 );
						med.push_back ( t2[ar[i]] );
						med.push_back ( ar[i] );
						med.push_back ( 1 );
						med.push_back ( n );
						break;
					}
				}
				if ( ans > 5 ) {
					lpi ( i, 1, ka ) {
						if ( deg[ar[i]] ^ ka ) {
							for ( int j = la[ar[i]]; ~j; j = edge[j].last ) tv[edge[j].v] = true;
							lpi ( j, 1, ka ) if ( tv[ar[j]] ) for ( int k = la[ar[j]]; ~k; k = edge[k].last ) if ( edge[k].v ^ ar[i] ) t22[edge[k].v] = ar[j];
							lpi ( j, 1, ka ) {
								if ( !tv[ar[j]] && t22[ar[j]] ) {
									ans = 5;
									med.clear ();
									med.push_back ( 1 );
									med.push_back ( ar[i] );
									med.push_back ( t22[ar[j]] );
									med.push_back ( ar[j] );
									med.push_back ( ar[i] );
									med.push_back ( n );
									break;
								}
							}
							if ( ans <= 5 ) break;
						}
					}
				}
			}
		}
	}

	printf ( "%d\n", ans == INF ? -1 : ans );
	if ( ans ^ INF ) {
		for ( auto x : med ) printf ( "%d ", x );
		putchar ( '\n' );
	}
}



void dfs ( int now )
{
	if ( vis[now] ) return;
	vis[now] = true;
	ar[++ka] = now;

	for ( int i = la[now]; ~i; i = edge[i].last ) dfs ( edge[i].v );
}