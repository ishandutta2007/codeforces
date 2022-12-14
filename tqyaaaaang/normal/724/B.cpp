#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
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
const int MAXN = 23;

int n, m;
int table[MAXN][MAXN];

void init ();
void input ();
void work ();

bool suc ();



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

	scanf ( "%d%d", &n, &m );
	
	lpi ( i, 1, n )
		lpi ( j, 1, m )
			scanf ( "%d", &table[i][j] );
}

void work ()
{
	// main work

	bool ans = false;

	if ( suc () ){
		ans = true;
	}else{
		lpi ( i, 1, m ){
			lpi ( j, i+1, m ){
				lpi ( k, 1, n ) swap ( table[k][i], table[k][j] );
				if ( suc() ){
					ans = true;
					break;
				}
				lpi ( k, 1, n ) swap ( table[k][i], table[k][j] );
			}
		}
	}

	printf ( ans ? "YES\n" : "NO\n" );
}



bool suc ()
{
	int unmatch;
	lpi ( i, 1, n ){
		unmatch = 0;
		lpi ( j, 1, m ){
			if ( table[i][j] ^ j ) ++unmatch;
		}

		if ( unmatch > 2 ) return false;
	}

	return true;
}