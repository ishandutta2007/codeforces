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
const int MAXN = 107;

int n, a, t[MAXN];

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

	cin >> n >> a;
	lpi ( i, 1, n ) cin >> t[i];
}

void work ()
{
	// main work

	int l, r, ans = 0;
	l = r = a;
	if ( t[a] ) ++ans;
	--l, ++r;

	while ( l > 0 || r <= n ){
		if ( l > 0 && r <= n ){
			if ( t[l] && t[r] ) ans += 2;
		}else if ( l > 0 ){
			if ( t[l] ) ++ans;
		}else if ( r <= n ){
			if ( t[r] ) ++ans;
		}

		--l, ++r;
	}

	cout << ans << endl;
}