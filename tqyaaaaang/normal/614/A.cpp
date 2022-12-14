#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;
const LL MAXN = 1e18;

int main()
{
	ios::sync_with_stdio ( false );

	LL l, r, k, nowans;
	bool flag = false;
	cin >> l >> r >> k;

	int maxlog = SC ( int, ( log ( SC ( LD, MAXN ) ) / log ( SC ( LD, k ) ) ) );

	nowans = 1;
	lp ( i, 0, (maxlog+1) ){
		if ( ( nowans >= l ) && ( nowans <= r ) ){
			cout << nowans << " ";
			flag = true;
		}

		nowans *= k;
	}

	if ( !flag )
		cout << -1;

	cout << endl;
}