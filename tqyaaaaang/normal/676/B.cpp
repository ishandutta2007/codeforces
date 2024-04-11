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
const int MAXN = 12;

int n, t;
LD have[MAXN][MAXN];

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

	cin >> n >> t;
}

void work ()
{
	// main work

	lp ( i, 0, t ){
		have[1][1] += 1;
		lpi ( j, 1, n ){
			lpi ( k, 1, j ){
				if ( have[j][k] > 1 ){
					have[j+1][k] += ( have[j][k] - 1 ) / 2;
					have[j+1][k+1] += ( have[j][k] - 1 ) / 2;
					have[j][k] = 1;
				}
			}
		}
	}

	int cc = 0;
	lpi ( i, 1, n ){
		lpi ( j, 1, i ){
			if ( have[i][j] >= 1 ) cc++;
		}
	}

	cout << cc << endl;
}