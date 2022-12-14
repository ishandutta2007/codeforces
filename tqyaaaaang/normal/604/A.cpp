#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(i,begin,end) for ( int i = begin; i < end; i++ )

const int INF = 0x3fffffff;

int main()
{
	ios::sync_with_stdio ( false );

	int m[5], w[5], hs, hu, maxi[5];
	LD score = 0;

	maxi[0] = 500;;
	lp(i,1,5) maxi[i] = maxi[i-1] + 500;
	lp(i,0,5) cin >> m[i];
	lp(i,0,5) cin >> w[i];
	cin >> hs >> hu;

	lp(i,0,5) score += max ( 0.3 * maxi[i], ( 1 - m[i] / 250.0 ) * maxi[i] - 50 * w[i] );
	score += 100 * hs;
	score -= 50 * hu;

	cout << static_cast < int > ( score + 0.0001 ) << endl;
}