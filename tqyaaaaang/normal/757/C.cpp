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
const int MAXM = 1000007;
const int MOD = 1e9 + 7;

int n, m, ng;
int ns[MAXN];
set < int > s[MAXM];
map < PII, int > now;
map < PII, int > ::iterator it;
map < PII, int > nid;
LL frac[MAXM];
int id[MAXM];

void init ();
void input ();
void inputq ();
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

	frac[0] = 1;
	lp ( i, 1, MAXM ) frac[i] = ( frac[i-1] * i ) % MOD;
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &m );
}

void inputq ()
{
	scanf ( "%d", &ng );
	lp ( i, 0, ng ) scanf ( "%d", &ns[i] );
}

void work ()
{
	// main work

	int kk = 0, maxi, nd;
	lpi ( i, 1, m ) s[kk].insert ( i ), id[i] = kk;

	lp ( _q, 0, n ){
		inputq ();

		now.clear ();
		lp ( i, 0, ng ){
			s[id[ns[i]]].erase ( ns[i] );
			++now[MP(ns[i],id[ns[i]])];
		}

		nid.clear ();
		for ( it = now.begin (); it != now.end (); ++it ){
			if ( nid.find ( MP(it->first.second,it->second) ) == nid.end () ){
				nid.insert ( MP ( MP ( it->first.second, it->second ), ++kk ) );
			}
		}

		maxi = 0;
		for ( it = now.begin (); it != now.end (); ++it ){
			nd = nid[MP(it->first.second,it->second)];
			s[nd].insert ( it->first.first );
			id[it->first.first] = nd;
			maxi = qmax ( maxi, it->second );
		}

		kk += maxi;
	}

	LL ans = 1;
	lpi ( i, 0, kk ){
		ans = ( ans * frac[s[i].size()] ) % MOD;
	}

	printf ( "%I64d\n", ans );
}