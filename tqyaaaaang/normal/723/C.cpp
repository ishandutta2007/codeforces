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
const int MAXN = 2007;

int n, m;
int a[MAXN];
int cc[MAXN];

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

	memset ( cc, 0, sizeof ( cc ) );

	cin >> n >> m;
	lp ( i, 0, n ){
		cin >> a[i];
		if ( a[i] <= m ) ++cc[a[i]];
	}
}

void work ()
{
	// main work

	int maxi = n / m, nc = 0;
	lpi ( i, 1, m ){
		cc[i] -= maxi;
		if ( cc[i] < 0 ) nc -= cc[i];
	}

	int p = 1;
	while ( p <= m && cc[p] >= 0 ) ++p;
	if ( p <= m ){
		lp ( i, 0, n ){
			if ( a[i] > m || cc[a[i]] > 0 ){
				if ( a[i] <= m ) --cc[a[i]];
				a[i] = p;
				++cc[p];
				while ( p <= m && cc[p] >= 0 ) ++p;
				if ( p > m ) break;
			}
		}
	}

	cout << maxi << " " << nc << endl;
	lp ( i, 0, n ) cout << a[i] << " ";
	cout << endl;
}