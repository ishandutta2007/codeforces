#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
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

int n;
/*int f[MAXN];
bool divi[MAXN];
bool isp[MAXN];*/

void init ();
void input ();
void work ();

bool isp ( int num );



int main()
{
	init();
	input();
	work ();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );

/*	INIT ( isp, true );
	isp[0] = isp[1] = false;
	lp ( i, 2, MAXN )
		if ( isp[i] )
			for ( int j = i * i; j < MAXN; j += i )
				isp[j] = false;
	isp[1] = true;

	INIT ( divi, false );
	f[1] = INF, f[2] = 1;
	lp ( i, 3, MAXN ){
		f[i] = -1;
		lpd ( j, i-1, 0 ){
			if ( isp[j] && i % j == 0 ){
				f[i] = j;
				break;
			}
		}
		
		lpi ( j, 2, i>>1 ){
			if ( f[j] + f[i-j] < f[i] ){
				f[i] = f[j] + f[i-j];
				printf ( "%d=%d+%d\n", i, j, i-j );
				divi[i] = true;

				if ( divi[j] || divi[i-j] ){
//					printf ( "Used %d!\n", i );
				}
			}
//			f[i] = qmin ( f[i], f[j] + f[i-j] );
		}
	}

	lp ( i, 1, MAXN ) printf ( "%d: %d\n", i, f[i] );*/
}

void input ()
{
	// input method

	scanf ( "%d", &n );
}

void work ()
{
	// main work

	if ( isp ( n ) ) printf ( "1\n" );
	else if ( !( n & 1 ) || isp ( n - 2 ) ) printf ( "2\n" );
	else printf ( "3\n" );
}



bool isp ( int num )
{
	if ( num < 2 ) return false;

	int size = sqrt ( SC ( double, num ) ) + 10;
	size = qmin ( size, num - 1 );

	lp ( i, 2, size )
		if ( num % i == 0 )
			return false;

	return true;
}