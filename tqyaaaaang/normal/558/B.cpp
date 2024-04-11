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
const int MAX = 1000007;

int n;
int a[MAXN], cc[MAX];

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
	lpi ( i, 1, n ) cin >> a[i];
}

void work ()
{
	// main work

	int maxi = 0;
	lpi ( i, 1, n ) ++cc[a[i]];
	lp ( i, 0, MAX ) maxi = qmax ( maxi, cc[i] );

	memset ( cc, 0, sizeof ( cc ) );
	int l = 1, r = 0, ml = 0, mr = INF, mn = -1;
	for ( ; ; --cc[a[l++]] ){
		if ( mn == -1 || cc[mn] < maxi ){
			++r;
			for ( ; r <= n; ++r ){
				++cc[a[r]];
				if ( cc[a[r]] == maxi ){
					mn = a[r];
					break;
				}
			}

			if ( r == n+1 ) break;
		}
		if ( mr - ml + 1 > r - l + 1 )
			ml = l, mr = r;
	}

	cout << ml << " " << mr << endl;
}