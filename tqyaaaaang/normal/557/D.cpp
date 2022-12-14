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
const int MAXN = 100007;
const int MAXM = 200007;

int n, m, k = 0, v;
LL ans = 0;
bool odd = false;
int edge[MAXM];
int nxt[MAXM];
int last[MAXN];
int level[MAXN];
int ena[MAXM];
bool vis[MAXN];
int cc[2];

void init ();
void input ();
void work ();

void dfs ( int now );
void dps ( int now );



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

	memset ( last, -1, sizeof ( last ) );

	cin >> n >> m;
	int u, v;
	lp ( i, 0, m ){
		cin >> u >> v;
		edge[k] = v;
		nxt[k] = last[u];
		last[u] = k;
		++k;
		edge[k] = u;
		nxt[k] = last[v];
		last[v] = k;
		++k;
	}
}

void work ()
{
	// main work

	if ( !m ){
		cout << "3 " << SC ( LL, n ) * ( n - 1 ) * ( n - 2 ) / 3 / 2 / 1 << endl;   // C ( n, 3 )
		return;
	}
	
	bool flag = false;
	lpi ( i, 1, n ){
		if ( last[i] ^ -1 && nxt[last[i]] ^ -1 ){
			flag = true;
			break;
		}
	}

	if ( !flag ){
		cout << "2 " << SC ( LL, m ) * ( n - 2 ) << endl;
		return;
	}

	memset ( ena, true, sizeof ( ena ) );
	memset ( vis, false, sizeof ( vis ) );
	memset ( level, 0, sizeof ( level ) );
	lpi ( i, 1, n ){
		if ( !level[i] ){
			level[i] = 1;
			cc[0] = cc[1] = 0;
			dfs ( i );
			if ( odd ){
				cout << "0 1" << endl;
				return;
			}

			dps ( i );
		}
	}

	cout << "1 " << ans << endl;
}



void dfs ( int now )
{
	++cc[level[now]&1];

	for ( int i = last[now]; i ^ -1; i = nxt[i] ){
		if ( ena[i] ){
			v = edge[i];
			if ( level[v] && !( ( level[now] - level[v] ) & 1 ) ){
				odd = true;
				return;
			}else if ( !level[v] ){
				level[v] = level[now] + 1;
				ena[i^1] = false;
				dfs ( v );

				if ( odd ) return;
			}
		}
	}
}

void dps ( int now )
{
	vis[now] = true;
	ans += cc[level[now]&1] - 1;
	--cc[level[now]&1];

	for ( int i = last[now]; i ^ -1; i = nxt[i] ){
		if ( !vis[edge[i]] )
			dps ( edge[i] );
	}
}