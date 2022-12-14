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

int n, m, k;
int coor[MAXN][2];
LL ans[MAXN];
AR(int) oprd[MAXN], oprl[MAXN], opld[MAXN], oplr[MAXN];

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

	scanf ( "%d%d%d", &n, &m, &k );
	lp ( i, 0, k )
		scanf ( "%d%d", &coor[i][0], &coor[i][1] );
}

void work ()
{
	// main work

	lp ( i, 0, k ){
		if ( coor[i][0] <= coor[i][1] ){
			oprl[coor[i][1]-coor[i][0]].push_back ( i );
		}
		if ( coor[i][0] >= coor[i][1] ){
			oprd[coor[i][0]-coor[i][1]].push_back ( i );
		}

		if ( n-coor[i][0] >= coor[i][1] ){
			opld[coor[i][0]+coor[i][1]].push_back ( i );
		}
		if ( n-coor[i][0] <= coor[i][1] ){
			oplr[coor[i][0]+coor[i][1]-n].push_back ( i );
		}

		ans[i] = LINF;
	}

	int nx = 0, ny = 0, dir = 0, delta;
	LL tim = 0;

	int size;
	while ( 1 ){
		if ( dir == 0 ){
			if ( !ny ){
				AR(int) &now = oprd[nx];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+coor[now[i]][1] );
			}else{
				AR(int) &now = oprl[ny];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+coor[now[i]][0] );
			}
			delta = qmin ( n-nx, m-ny );
			nx += delta, ny += delta;

			if ( nx == n )
				dir = 1;
			else
				dir = 2;
		}else if ( dir == 1 ){
			if ( !ny ){
				AR(int) &now = opld[nx];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+coor[now[i]][1] );
			}else{
				AR(int) &now = oplr[ny];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+nx-coor[now[i]][0] );
			}
			delta = qmin ( nx, m-ny );
			nx -= delta, ny += delta;

			if ( !nx )
				dir = 0;
			else
				dir = 3;
		}else if ( dir == 2 ){
			delta = qmin ( n-nx, ny );
			nx += delta, ny -= delta;
			if ( !ny ){
				AR(int) &now = opld[nx];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+delta-coor[now[i]][1] );
				dir = 0;
			}else{
				AR(int) &now = oplr[ny];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+delta-nx+coor[now[i]][0] );
				dir = 3;
			}
		}else{
			delta = qmin ( nx, ny );
			nx -= delta, ny -= delta;
			if ( !ny ){
				AR(int) &now = oprd[nx];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+delta-coor[now[i]][1] );
				dir = 1;
			}else{
				AR(int) &now = oprl[ny];
				size = now.size();
				lp ( i, 0, size ) ans[now[i]] = qmin ( ans[now[i]], tim+delta-coor[now[i]][0] );
				dir = 2;
			}
		}

		tim += delta;

		if ( ( !nx || nx == n )&& ( !ny || ny == m ) ) break;
	}

	lp ( i, 0, k )
		printf ( "%I64d\n", ( ans[i] ^ LINF ) ? ans[i] : -1 );
}