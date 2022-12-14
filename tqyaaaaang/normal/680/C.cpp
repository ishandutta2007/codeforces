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
const int MAX = 55;

bool isp[MAX];

int n;

void init ();
void input ();
void work ();



int main()
{
	init();
//	input();
	work();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );

	lp ( i, 0, MAX ) isp[i] = true;
	lp ( i, 2, MAX ){
		if ( isp[i] ){
			for ( int j = i * i; j < MAX; j += i ) isp[j] = false;
		}
	}
}

void input ()
{
	// input method
}

void work ()
{
	// main work

	int div = 0;
	char reply[100];
	lp ( i, 2, MAX ){
		if ( isp[i] ){
			printf ( "%d\n", i );
			fflush ( stdout );
			scanf ( "%s", reply );
			if ( reply[0] == 'y' ){
				++div;
				if ( div >= 2 ) break;
			}

			if ( i*i <= 100 ){
				printf ( "%d\n", i*i );
				fflush ( stdout );
				scanf ( "%s", reply );
				if ( reply[0] == 'y' ){
					div = 3;
					break;
				}
			}
		}
	}

	cout << ( ( div >= 2 ) ? "composite" : "prime" ) << endl;
	cout.flush();
}