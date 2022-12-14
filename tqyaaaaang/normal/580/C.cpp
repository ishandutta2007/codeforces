#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( int loop = start; loop < end; loop++ )
#define lpd(loop,start,end) for ( int loop = start; loop > end; loop-- )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; loop++ )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; loop-- )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 1e5+7;

int hc[MAXN];
bool vis[MAXN];
AR(AR(int)) tree;
int ans = 0, m;

void dfs ( int ind, int met );

int main()
{
	ios::sync_with_stdio ( false );

	memset ( vis, false, sizeof ( vis ) );

	int n, x, y;
	cin >> n >> m;
	tree.resize ( n+1 );
	lpi ( i, 1, n ) cin >> hc[i];
	lp ( i, 0, n-1 ){
		cin >> x >> y;
		tree[x].push_back ( y );
		tree[y].push_back ( x );
	}

	dfs ( 1, 0 );

	cout << ans << endl;
}

void dfs ( int ind, int met )
{
	vis[ind] = true;

	if ( hc[ind] ) met++;
	else met = 0;
	if ( met > m ) return;
	
	bool flag = false;
	int size = tree[ind].size();
	lp ( i, 0, size ){
		if ( !vis[tree[ind][i]] ){
			dfs ( tree[ind][i], met );
			flag = true;
		}
	}

	if ( !flag ) ans++;
}