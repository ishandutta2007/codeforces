#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

int gcd ( int a, int b )
{
	return ( ( !b ) ? a : gcd ( b, a%b ) );
}

int main()
{
	ios::sync_with_stdio ( false );

	int n, k;
	cin >> n;
	list < int > l;
	lp ( i, 0, n ){
		cin >> k;
		l.push_back ( k );
	}

	list < int > ::iterator it, itt;

	it = itt = l.begin();
	it++;
	k = 0;
	for ( ; it != l.end(); it++, itt++ ){
		if ( gcd ( *it, *itt ) > 1 ){
			k++;
			l.insert ( it, 1 );
			itt++;
		}
	}

	cout << k << endl;
	for ( it = l.begin(); it != l.end(); it++ ){
		cout << *it << " ";
	}
	cout << endl;
}