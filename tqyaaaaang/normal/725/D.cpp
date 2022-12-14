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
const int MAXN = 300007;

struct tT
{
	bool operator < ( const tT &a ) const
	{
		return ( ( t ^ a.t ) ? ( t > a.t ) : ( w < a.w ) );
	}

	LL t, w;
}team[MAXN];

int n;
LL tt[MAXN];
int cc[MAXN];
priority_queue < LL, AR(LL), greater < LL > > q;

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

	cin >> n;
	lp ( i, 0, n )
		cin >> team[i].t >> team[i].w;
}

void work ()
{
	// main work

	sort ( team+1, team+n );

	LL nt = team[0].t, nb = 0;

	memset ( tt, -1, sizeof ( tt ) );
	int now = 0, rnk = 0, ii = INF;
	lp ( i, 1, n ){
		if ( team[i].t > nt ){
			++rnk;
			q.push ( team[i].w - team[i].t + 1 );
		}else{
			ii = qmin ( ii, i );
			if ( team[i].t == tt[now-1] ) ++cc[now-1];
			else{
				tt[now] = team[i].t;
				cc[now] = 1;
				++now;
			}
		}
	}

	++rnk;
	if ( !now || team[now-1].t ){
		tt[now] = 0;
		cc[now] = 0;
		++now;
	}else
		++cc[now-1];

	int mini = rnk;
	LL tmp;
	lp ( i, 0, now ){
		nb += nt - tt[i];
		nt = tt[i];

		while ( !q.empty() ){
			tmp = q.top();
			if ( tmp > nb ) break;

			nb -= tmp;
			q.pop();
			--rnk;
		}

		mini = qmin ( mini, rnk );

		rnk += cc[i];
		for ( int j = 0; j < cc[i]; ++j, ++ii )
			q.push ( team[ii].w - team[ii].t + 1 );
	}

	cout << mini << endl;
}