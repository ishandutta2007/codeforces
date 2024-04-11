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
const int MAX = 200007;

int n, maxi;
int a[MAXN];
int cr[MAX];
int st[MAX];

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
		cin >> a[i];
		maxi = qmax ( maxi, a[i] );
	}
}

void work ()
{
	// main work

	maxi *= 2;
	memset ( cr, 0, sizeof ( cr ) );
	memset ( st, 0, sizeof ( st ) );

	bool flag;
	int now, cur, step, tst;
	lp ( i, 0, n ){
		now = a[i];
		flag = true;
		step = 0;
		for ( ; now; now >>= 1, ++step ){
			++cr[now];
			st[now] += step;
			if ( flag )
				for ( cur = ( now << 1 ), tst = step + 1; cur <= maxi; cur <<= 1, ++tst )
					++cr[cur], st[cur] += tst;
			flag = now & 1;
		}
	}

	int mini = INF;
	lpi ( i, 1, maxi )
		if ( cr[i] == n )
			mini = qmin ( mini, st[i] );

	cout << mini << endl;
}