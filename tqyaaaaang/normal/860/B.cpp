#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned long long
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
#define US unordered_set
#define UM unordered_map

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 70007;
const int MAXL = 13;
const ULL MUL = 99793;

int n, len = 9;
char s[MAXN][MAXL];
UM < ULL, int > mp;
US < ULL > ts;
US < ULL > ::iterator it;

void init ();
void input ();
void work ();

ULL gethsh ( char s[], int l, int r );



int main ()
{
	init ();
	input ();
	work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%s", s[i]+1 );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) {
		ts.clear ();
		lpi ( j, 1, len ) {
			lpi ( k, j, len ) {
				ts.insert ( gethsh ( s[i], j, k ) );
			}
		}

		for ( it = ts.begin (); it != ts.end (); ++it ) {
			++mp[*it];
		}
	}

	bool flag;
	lpi ( i, 1, n ) {
		lpi ( j, 1, len ) {
			flag = false;
			lpi ( k, 1, len-j+1 ) {
				if ( mp[gethsh ( s[i], k, k+j-1 )] == 1 ) {
					flag = true;
					lp ( a, 0, j ) {
						putchar ( s[i][k+a] );
					}
					putchar ( '\n' );
					break;
				}
			}
			if ( flag ) break;
		}
	}
}



ULL gethsh ( char s[], int l, int r )
{
	ULL ans = 0;
	lpi ( i, l, r ) ans = ans * MUL + s[i];
	return ans;
}