#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

int main()
{
	ios::sync_with_stdio ( false );

	int minw = INF, minb = INF, nmw, nmb;
	char board[8][8];
	
	lp ( i, 0, 8 ) lp ( j, 0, 8 ) cin >> board [i][j];

	lp ( j, 0, 8 ){
		nmw = nmb = -1;
		lp ( i, 0, 8 ){
			if ( board[i][j] == 'B' )
				nmb = i;
			else if ( board[i][j] == 'W')
				nmb = -1;
		}

		if ( nmb != -1 )
			minb = min ( minb, 7-nmb );

		for ( int i = 7; i >= 0; i-- ){
			if ( board[i][j] == 'W' )
				nmw = i;
			else if ( board[i][j] == 'B' )
				nmw = -1;
		}

		if ( nmw != -1 )
			minw = min ( minw, nmw );
	}

	cout << ( ( minw <= minb ) ? "A" : "B" ) << endl;
}