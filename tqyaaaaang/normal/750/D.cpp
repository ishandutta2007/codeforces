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
const int MAXN = 357;
const int MAXT = 157;

const int MOVE[8][2] =
{
	0, 1,
	1, 1,
	1, 0,
	1, -1,
	0, -1,
	-1, -1,
	-1, 0,
	-1, 1
};

const int SPL[8][2] =
{
	1, 7,
	2, 0,
	3, 1,
	4, 2,
	5, 3,
	6, 4,
	7, 5,
	0, 6
};

struct qT
{
	void setd ( int _x, int _y, int _d )
	{
		x = _x, y = _y, d = _d;
	}

	int x, y, d;
}q1[MAXN*MAXN*8], q2[MAXN*MAXN*8];

int n;
int t[MAXN];
bool cov[MAXN][MAXN];
bool vis[MAXN][MAXN][8];
bool spl[MAXN];

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

	scanf ( "%d", &n );
	lp ( i, 0, n ) scanf ( "%d", &t[i] );
}

void work ()
{
	// main work

	int l, r, ll, rr;
	qT *lq = q1, *nq = q2, *swt;
	qT now;
	int nx, ny, nd, vx, vy, vd;
	ll = rr = 0;
	lq[rr++].setd ( MAXT, MAXT, 0 );
	lp ( i, 1, n ) t[i] += t[i-1];
	INIT ( spl, false );
	lp ( i, 0, n ) spl[t[i]] = true;
	INIT ( cov, false );
	lpi ( _t, 1, t[n-1] ){
		INIT ( vis, false );
		
		l = ll, r = rr;
		ll = rr = 0;

		while ( l < r ){
			now = lq[l++];
			nx = now.x, ny = now.y, nd = now.d;

			cov[nx][ny] = true;

			if ( spl[_t] ){
				lp ( i, 0, 2 ){
					vd = SPL[nd][i];
					vx = nx+MOVE[vd][0], vy = ny+MOVE[vd][1];
					if ( !vis[vx][vy][vd] ){
						vis[vx][vy][vd] = true;
						nq[rr++].setd ( vx, vy, vd );
					}
				}
			}else{
				vd = nd;
				vx = nx+MOVE[vd][0], vy = ny+MOVE[vd][1];
				if ( !vis[vx][vy][vd] ){
					vis[vx][vy][vd] = true;
					nq[rr++].setd ( vx, vy, vd );
				}
			}
		}

		swt = lq;
		lq = nq;
		nq = swt;
	}

	int ans = 0;
	lp ( i, 0, MAXN ) lp ( j, 0, MAXN ) ans += cov[i][j];
	printf ( "%d\n", ans );
}