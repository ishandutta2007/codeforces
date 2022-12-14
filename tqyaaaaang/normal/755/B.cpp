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
const int MAXN = 1007;

int n, m, kc;
int pid[MAXN], eid[MAXN];
map < string, int > mp;
map < string, int > ::iterator it;

void init ();
void input ();
void work ();

int getid ( string &str )
{
	if ( ( it = mp.find ( str ) ) == mp.end () ){
		mp[str] = kc++;
		return kc-1;
	}else
		return it->second;
}



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

	cin >> n >> m;

	kc = 0;
	string tmp;
	lp ( i, 0, n ){
		cin >> tmp;
		pid[i] = getid ( tmp );
	}
	lp ( i, 0, m ){
		cin >> tmp;
		eid[i] = getid ( tmp );
	}
}

void work ()
{
	// main work

	int cp = n, ce = m, con = 0;
	lp ( i, 0, n ) lp ( j, 0, m ) if ( pid[i] == eid[j] ) ++con, --cp, --ce;

	if ( con & 1 ) --ce;
	printf ( ( cp > ce ) ? "YES\n" : "NO\n" );
}