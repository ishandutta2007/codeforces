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
const int MAXN = 0;

int n, mi[3], ma[3], ans[3];

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
	lp ( i, 0, 3 ) cin >> mi[i] >> ma[i];
}

void work ()
{
	// main work

	int sum = 0;
	lp ( i, 0, 3 ) sum += mi[i];
	lp ( i, 0, 3 ) ans[i] = mi[i];

	ans[0] = qmin ( ma[0], n - mi[1] - mi[2] );
	ans[1] = qmin ( ma[1], n - ans[0] - mi[2] );
	ans[2] = qmin ( ma[2], n - ans[0] - ans[1] );

	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}