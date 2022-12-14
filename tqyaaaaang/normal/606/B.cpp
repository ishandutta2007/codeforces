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

	int x, y, x0, y0, nx, ny, size;
	string ops;

	cin >> x >> y >> x0 >> y0;

	vector < vector < bool > > map ( x+1 );
	lp ( i, 1, ( x+1 ) ) map[i].resize ( y+1, false );

	cin >> ops;
	size = ops.size();
	nx = x0;
	ny = y0;
	lp ( i, 0, size ){
		cout << ( map[nx][ny] ? 0 : 1 ) << " ";
		map[nx][ny] = true;

		switch ( ops[i] ){
		case 'L':
			if ( ny > 1 ) ny--;
			break;

		case 'R':
			if ( ny < y ) ny++;
			break;

		case 'U':
			if ( nx > 1 ) nx--;
			break;

		case 'D':
			if ( nx < x ) nx++;
			break;
		}
	}

	int remain = 0;
	lp ( i, 1, ( x+1 ) ){
		lp ( j, 1, ( y+1 ) ){
			if ( !map[i][j] ) remain++;
		}
	}

	cout << remain << endl;
}