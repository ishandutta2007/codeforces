#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( LL loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( LL loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( LL loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( LL loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const LL INF = 0x3fffffff;
const LL SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const LL MAXN = 507;

LL n, r, c;
LL grid[MAXN][MAXN];

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

	cin >> n;
	lp ( i, 0, n ){
		lp ( j, 0, n ){
			cin >> grid[i][j];
			if ( !grid[i][j] ) r = i, c = j;
		}
	}
}

void work ()
{
	// main work

	if ( n == 1 ){
		cout << 1 << endl;
		return;
	}

	LL t = ( r ? 0 : 1 ), sum = 0, ts;
	lp ( i, 0, n ) sum += grid[t][i];

	ts = 0;
	lp ( i, 0, n ) ts += grid[r][i];
	LL num = sum - ts;

	if ( num <= 0 ){
		cout << -1 << endl;
		return;
	}

	grid[r][c] = num;
	lp ( i, 0, n ){
		ts = 0;
		lp ( j, 0, n ){
			ts += grid[i][j];
		}

		if ( ts ^ sum ){
			cout << -1 << endl;
			return;
		}
	}

	lp ( j, 0, n ){
		ts = 0;
		lp ( i, 0, n ){
			ts += grid[i][j];
		}

		if ( ts ^ sum ){
			cout << -1 << endl;
			return;
		}
	}

	ts = 0;
	lp ( i, 0, n ){
		ts += grid[i][i];
	}

	if ( ts ^ sum ){
		cout << -1 << endl;
		return;
	}

	ts = 0;
	lp ( i, 0, n ){
		ts += grid[i][n-i-1];
	}

	if ( ts ^ sum ){
		cout << -1 << endl;
		return;
	}

	cout << num << endl;
}