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

int a[5];

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

	lp ( i, 0, 5 ) cin >> a[i];
}

void work ()
{
	// main work

	int sum = 0;
	lp ( i, 0, 5 ) sum += a[i];

	int mini = sum;
	lp ( i, 0, 5 ){
		lp ( j, 0, 5 ){
			if ( i != j && a[i] == a[j] ){
				mini = qmin ( mini, sum - a[i] - a[j] );
			}
		}
	}
	lp ( i, 0, 5 ){
		lp ( j, 0, 5 ){
			lp ( k, 0, 5 ){
				if ( i != j && j != k && i != k && a[i] == a[j] && a[i] == a[k] ){
					mini = qmin ( mini, sum - a[i] - a[j] - a[k] );
				}
			}
		}
	}

	cout << mini << endl;
}