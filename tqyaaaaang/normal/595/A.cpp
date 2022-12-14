#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio ( false );

	int n, m, temp;
	cin >> n >> m;
	
	vector < vector < int > > building ( n );

	for ( int i = 0; i < n; i++ ){
		building[i].resize ( 2 * m );
		for ( int j = 0; j < 2 * m; j++ ){
			cin >> temp;
			building[i][j] = ( temp == 1 );
		}
	}

	int cc = 0;
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < m; j++ ){
			if ( building[i][2*j] | building[i][2*j+1] ) cc++;
		}
	}

	cout << cc << endl;
}