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
const int MAXN = 1007;
const int MOD = 16;
const int FL = 1, FU = 2, FR = 4, FD = 8;
const int BL = 0, BU = 1, BR = 2, BD = 3;
const int rev[4] = { 2, 3, 0, 1 };
const int nm[4][2] = {
	0, -1,
	-1, 0,
	0, 1,
	1, 0
};

struct qT
{
	int x, y, rot;
}q[MAXN*MAXN*4*2];

int grid[MAXN][MAXN];
int ans[MAXN][MAXN][4];
int n, m, xt, yt, xm, ym;

map < char, int > cti;

void init ();
void input ();
void work ();

int trans ( int x, int y, int rot );



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

	cti.insert ( make_pair ( '+', FL+FU+FR+FD ) );
	cti.insert ( make_pair ( '-', FL+FR ) );
	cti.insert ( make_pair ( '|', FU+FD ) );
	cti.insert ( make_pair ( '^', FU ) );
	cti.insert ( make_pair ( '>', FR ) );
	cti.insert ( make_pair ( '<', FL ) );
	cti.insert ( make_pair ( 'v', FD ) );
	cti.insert ( make_pair ( 'L', FU+FR+FD ) );
	cti.insert ( make_pair ( 'R', FL+FU+FD ) );
	cti.insert ( make_pair ( 'U', FL+FR+FD ) );
	cti.insert ( make_pair ( 'D', FL+FU+FR ) );
	cti.insert ( make_pair ( '*', 0 ) );

	memset ( ans, -1, sizeof ( ans ) );
}

void input ()
{
	// input method

	cin >> n >> m;
	char tin;
	lp ( i, 0, n ){
		lp ( j, 0, m ){
			cin >> tin;
			grid[i][j] = cti[tin];
		}
	}

	cin >> xt >> yt >> xm >> ym;
	xt--, yt--, xm--, ym--;
}

void work ()
{
	// main work
	int l, r, x, y, rot, nr, sn, s[4], nx, ny;
	l = r = 0;
	
	q[r].x = xt;
	q[r].y = yt;
	q[r].rot = 0;
	++r;
	ans[xt][yt][0] = 0;

	while ( l < r ){
		x = q[l].x;
		y = q[l].y;
		rot = q[l].rot;

		++l;
		nr = rot + 1;
		if ( nr == 4 ) nr = 0;
		if ( ans[x][y][nr] == -1 ){
			ans[x][y][nr] = ans[x][y][rot] + 1;
			q[r].x = x;
			q[r].y = y;
			q[r].rot = nr;
			++r;
		}

		sn = trans ( x, y, rot );
		s[BU] = trans ( x-1, y, rot );
		s[BD] = trans ( x+1, y, rot );
		s[BL] = trans ( x, y-1, rot );
		s[BR] = trans ( x, y+1, rot );

		lp ( i, 0, 4 ){
			if ( ( ( sn >> i ) & 1 ) && ( ( s[i] >> rev[i] ) & 1 ) && ( ans[nx=(x+nm[i][0])][ny=(y+nm[i][1])][rot] == -1 ) ){
				ans[nx][ny][rot] = ans[x][y][rot] + 1;
				q[r].x = nx;
				q[r].y = ny;
				q[r].rot = rot;
				++r;
			}
		}
	}

	int mini = INF;
	lp ( i, 0, 4 ) if ( ans[xm][ym][i] != -1 ) mini = qmin ( mini, ans[xm][ym][i] );
	cout << ( ( mini == INF ) ? -1 : mini ) << endl;
}

int trans ( int x, int y, int rot )
{
	if ( ( x < 0 ) || ( x >= n ) || ( y < 0 ) || ( y >= m ) ) return 0;

	int sta = grid[x][y];
	sta <<= rot;
	sta += sta / MOD;
	sta %= MOD;
	return sta;
}