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
const int MAXN = 507;

int n, k;
int a[MAXN], b[MAXN];

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

	cin >> n >> k;
	lp ( i, 0, n ) cin >> a[i];
}

void work ()
{
	// main work

	lp ( i, 0, n ) b[i] = a[i];

	int sum = 0;
	lp ( i, 1, n ){
		if ( b[i-1] + b[i] < k ){
			sum += k - b[i-1] - b[i];
			b[i] = k - b[i-1];
		}
	}

	cout << sum << endl;
	lp ( i, 0, n ) cout << b[i] << " ";
	cout << endl;
}