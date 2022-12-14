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
const int MAXK = 7;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];

LL ans;
int n, k;
int ke, la[MAXN];
LL cc[MAXN][MAXK];
LL sum[MAXN][MAXK];

void init ();
void input ();
void work ();

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

	scanf ( "%d%d", &n, &k );
	int u, v;
	ke = 0;
	INIT ( la, -1 );
	lp ( i, 1, n ){
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

	ans = 0;
	dfs ( 1, -1 );

	printf ( "%I64d\n", ans );
}



void dfs ( int now, int fa )
{
	LL tc[MAXK] ={ 0 }, ts[MAXK] ={ 0 };
	int v;
	for ( int i = la[now]; ~i; i = edge[i].last ){
		if ( ( v = edge[i].v ) ^ fa ){
			dfs ( v, now );
			lp ( j, 0, k ) ans += sum[v][j];
			lp ( j, 0, k ){
				lp ( a, 0, k ){
					ans += ts[j] * cc[v][a] + tc[j] * sum[v][a];
					if ( j && a && j + a <= k ) ans -= tc[j] * cc[v][a];
				}
			}
			lp ( j, 0, k ) ts[j] += sum[v][j], tc[j] += cc[v][j];
		}
	}

	++tc[0];
	lp ( j, 0, k ) cc[now][( j+1 )%k] = tc[j], sum[now][( j+1 )%k] = ts[j];
	sum[now][1%k] += cc[now][1%k];
}