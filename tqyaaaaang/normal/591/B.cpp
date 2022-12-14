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

	char change[26];
	lp ( i, 0, 26 ) change[i] = i+'a';

	int n, m;
	char x, y;
	string str;
	cin >> n >> m >> str;

	lp ( i, 0, m ){
		cin >> x >> y;

		lp ( i, 0, 26 ){
			if ( change[i] == x ) change[i] = y;
			else if ( change[i] == y ) change[i] = x;
		}
	}

	lp ( i, 0, n ){
		cout << change[str[i]-'a'];
	}
	cout << endl;
}