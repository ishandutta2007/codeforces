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

char s[MAXN];
int n, k;

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

	cin >> n >> k >> s;
}

void work ()
{
	// main work

	int nd, l, r, maxi, diff;
	char dif;

	maxi = 0;
	for ( dif = 'a'; dif <= 'b'; dif++ ){
		l = r = diff = 0;
		while ( r < n ){
			if ( s[r] == dif ) diff++;
			while ( diff > k ){
				if ( s[l] == dif ) diff--;
				l++;
			}

			maxi = qmax ( maxi, r - l + 1 );

			r++;
		}
	}

	cout << maxi << endl;
}