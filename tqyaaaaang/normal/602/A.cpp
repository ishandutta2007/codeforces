#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio ( false );

	int n, m, bx, by, temp;
	long long x = 0, y = 0;

	cin >> n >> bx;
	for ( int i = 0; i < n; i++ ){
		cin >> temp;
		x = x * bx + temp;
	}
	
	cin >> m >> by;
	for ( int i = 0; i < m; i++ ){
		cin >> temp;
		y = y * by + temp;
	}

	if ( x < y )
		cout << "<";
	else if ( x > y )
		cout << ">";
	else   // x = y
		cout << "=";
}