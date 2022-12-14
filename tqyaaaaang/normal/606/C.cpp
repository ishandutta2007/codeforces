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

	int n, temp, maxi, now;

	cin >> n;

	vector < int > place ( n );
	vector < bool > connection ( n-1 );
	lp ( i, 0, n ){
		cin >> temp;
		temp--;
		place[temp] = i;
	}

	lp ( i, 0, ( n-1 ) )
		connection[i] = ( place[i] < place[i+1] );

	maxi = now = 1;
	lp ( i, 0, ( n-1 ) ){
		if ( connection[i] )
			now++;
		else{
			maxi = max ( now, maxi );
			now = 1;
		}
	}

	maxi = max ( now, maxi );

	cout << ( n - maxi ) << endl;
}