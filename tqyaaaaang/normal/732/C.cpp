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
const int MAXN = 3;

LL t[MAXN];
bool tag[MAXN];

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

	lp ( i, 0, MAXN ) cin >> t[i];
}

void work ()
{
	// main work

	LL maxi, mini = LINF, tmp;
	lp ( l, 0, MAXN ){
		lp ( r, 0, MAXN ){
			memset ( tag, false, sizeof ( tag ) );
			for ( int i = l; i ^ r; i = ( i + 1 ) % MAXN ) tag[i] = true;
			tag[r] = true;
			
			maxi = 0;
			lp ( i, 0, MAXN ) maxi = qmax ( maxi, t[i] - ( tag[i] ? 1 : 0 ) );
			tmp = 0;
			lp ( i, 0, MAXN ){
				tmp += maxi + ( tag[i] ? 1 : 0 ) - t[i];
			}
			mini = qmin ( mini, tmp );
		}
	}

	cout << mini << endl;
}