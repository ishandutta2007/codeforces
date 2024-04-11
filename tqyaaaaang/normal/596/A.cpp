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

	int n;
	int ver[4][2];
	
	cin >> n;
	lp ( i, 0, n ){
		cin >> ver[i][0] >> ver[i][1];
	}

	if ( n == 1 ) cout << "-1" << endl;
	else if ( n == 2 ){
		if ( ( ver[0][0] != ver[1][0] ) && ( ver[0][1] != ver[1][1] ) )
			cout << ( abs ( ver[0][0] - ver[1][0] ) * abs ( ver[0][1] - ver[1][1] ) ) << endl;
		else cout << "-1" << endl;
	}else{
		bool flag = false;
		for ( int i = 0;  ( i < n ) && ( !flag ); i++ ){
			for ( int j = i + 1; j < n; j++ ){
				if ( ( ver[i][0] != ver[j][0] ) && ( ver[i][1] != ver[j][1] ) ){
					cout << ( abs ( ver[i][0] - ver[j][0] ) * abs ( ver[i][1] - ver[j][1] ) ) << endl;
					flag = true;
					break;
				}
			}
		}
	}
}