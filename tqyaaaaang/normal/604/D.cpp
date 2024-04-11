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

	const int MOD = 1e9+7;

	int p, k;
	LL ans;
	cin >> p >> k;

	vector < bool > pos ( p, false );

	ans = ( ( k == 1 ) ? p : 1 );
	pos[0] = true;
	lp(i,1,p){
		if ( !pos[i] ){
			pos[i] = true;
			ans *= p;
			ans %= MOD;

			for ( int j = ( SC( LL, i ) * k ) % p; !pos[j]; j = ( SC( LL, j ) * k ) % p ){
				pos[j] = true;
			}
		}
	}

	cout << ans << endl;
}