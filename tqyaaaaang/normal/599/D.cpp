#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;
const int MAXSIZE = 10000007;

LL ans[MAXSIZE][2];

int main()
{
	ios::sync_with_stdio ( false );

	LL x, ansn = 0, base = 0, plus = 0;
	cin >> x;

	for ( LL i = 1; ; i++ ){
		base += i * i;
		plus += i;

		if ( base > x ) break;

		if ( ( x - base ) % plus == 0 ){
			ans[ansn][0] = i;
			ans[ansn][1] = i + ( x - base ) / plus;
			ansn++;
		}
	}

	for ( int i = ansn-1; i >= 0; i-- ){
		if ( ans[i][0] != ans[i][1] ){
			ans[ansn][0] = ans[i][1];
			ans[ansn][1] = ans[i][0];
			ansn++;

			if ( ansn >= MAXSIZE ){
				return -10;
			}
		}
	}

	cout << ansn << endl;
	lp ( i, 0, ansn ){
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
}