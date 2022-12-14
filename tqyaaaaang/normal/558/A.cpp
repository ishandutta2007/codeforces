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
const int MAXN = 107;

struct tT
{
	bool operator < ( const tT &n ) const
	{
		return x < n.x;
	}

	int x, a;
}tree[MAXN];

int n, pos;

void init ();
void input ();
void work ();

int getsum ( int ind, int dir );



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
	lp ( i, 0, n ) cin >> tree[i].x >> tree[i].a;
}

void work ()
{
	// main work

	pos = -1;
	sort ( tree, tree+n );
	lp ( i, 0, n ){
		if ( tree[i].x > 0 ){
			pos = i;
			break;
		}
	}

	if ( !pos )
		cout << tree[0].a << endl;
	else if ( pos == -1 )
		cout << tree[n-1].a << endl;
	else
		cout << qmax ( getsum ( pos-1, 1 ), getsum ( pos, -1 ) ) << endl;
}



int getsum ( int ind, int dir )
{
	int l, r;
	int ans = tree[ind].a;
	l = r = ind;

	while ( 1 ){
		if ( dir == 1 ){
			if ( ++r >= n ) break;
			ans += tree[r].a;
			dir = -1;
		}else{
			if ( --l < 0 ) break;
			ans += tree[l].a;
			dir = 1;
		}
	}

	return ans;
}