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

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];

int n;
int ke, la[MAXN];
int deg[MAXN];

void init ();
void input ();
void work ();

int dfs ( int now, int fa )
{
	if ( deg[now] == 1 ) return now;
	for ( int i = la[now]; ~i; i = edge[i].last ) if ( edge[i].v ^ fa ) return dfs ( edge[i].v, now );
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

	cin >> n;
	int u, v;
	INIT ( la, -1 );
	lp ( i, 1, n ) {
		cin >> u >> v;
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

	int rt = max_element ( deg + 1, deg + 1 + n ) - deg;

	lpi ( i, 1, n ) {
		if ( ( i ^ rt ) && deg[i] > 2 ) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
	cout << deg[rt] << endl;
	for ( int i = la[rt]; ~i; i = edge[i].last ) cout << rt << " " << dfs ( edge[i].v, rt ) << endl;
}