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
const int MAXN = 100007;
const int MAX = 207;

struct legT
{
	bool operator < ( const legT &a ) const
	{
		return ( l < a.l );
	}

	int l, d;
}leg[MAXN];

int n;
int cc[MAX];

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
	lp ( i, 0, n ) cin >> leg[i].l;
	lp ( i, 0, n ) cin >> leg[i].d;
}

void work ()
{
	// main work

	int cost = 0;
	lp ( i, 0, n ) cost += leg[i].d;

	sort ( leg, leg+n );

	memset ( cc, 0, sizeof ( cc ) );
	int num, mini = INF, need, req, nxt;
	leg[n].l = INF;
	for ( int i = 0; i < n; i = nxt ){
		for ( nxt = i, num = 0; leg[nxt].l == leg[i].l; ++nxt, ++num ) cost -= leg[nxt].d;

		req = cost;
		need = i - num + 1;
		lp ( j, 0, MAX ){
			req += qmin ( need, cc[j] ) * j;
			need -= cc[j];

			if ( need <= 0 ) break;
		}

		mini = qmin ( mini, req );

		for ( nxt = i, num = 0; leg[nxt].l == leg[i].l; ++nxt, ++num ) ++cc[leg[nxt].d];
	}

	cout << mini << endl;
}