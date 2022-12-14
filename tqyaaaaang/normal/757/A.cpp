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
const int MAXN = 100007;
const int BASE = 257;
const int MAXP = 13;

const char pat[MAXP] = "Bulbasaur";

int n;
char s[MAXN];
int cc[MAXN];
int need[MAXN];

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

	INIT ( need, 0 );
	lp ( i, 0, 9 ) ++need[pat[i]];
}

void input ()
{
	// input method

	scanf ( "%s", s );
}

void work ()
{
	// main work

	int n = strlen ( s );

	INIT ( cc, 0 );
	lp ( i, 0, n ) ++cc[s[i]];

	int ans = 0;
	bool flag;
	while ( 1 ){
		flag = true;
		lp ( i, 0, BASE ){
			if ( cc[i] < need[i] ){
				flag = false;
				break;
			}
		}

		if ( !flag ) break;

		++ans;
		lp ( i, 0, BASE ) cc[i] -= need[i];
	}

	printf ( "%d\n", ans );
}