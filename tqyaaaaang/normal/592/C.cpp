#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

LL gcd ( LL a, LL b )
{
	return ( ( b == 0 ) ? a : gcd ( b, a % b ) );
}

int main()
{
	ios::sync_with_stdio ( false );

	LL t, v1, v2, mv, gv, lcm, cmc, mcm, p, q, g;   // mv: min ( v1, v2 )   gv: gcd ( v1, v2 )   lcm: lcm ( v1, v2 )   lc: the number of cm   mcm: maximum cm   g: gcd ( p, q )   p and q: the answer is p/q
	LL tlcm;   // a temp flag of overflowing while calculating lcm
	cin >> t >> v1 >> v2;
	mv = min ( v1, v2 );
	if  ( mv > t ){ cout << "1/1" << endl; return 0; }
	gv = gcd ( v1, v2 );
	tlcm = ( t / v1 + 1 ) * gv;
	if ( tlcm < v2 ){
		p = mv-1;
		q = t;
		g = gcd ( p, q );
		cout << p/g << "/" << q/g << endl;
		return 0;
	}
	lcm = v1 / gv;
	lcm *= v2;
	cmc = t / lcm;
	mcm = cmc * lcm;
	cmc--;   // discuss the one beside the destination independently
	p = cmc * mv;
	p += mv - 1;   // beside the starting point, before min ( v1, v2 )
	p += min ( t - mcm + 1, mv );
	q = t;

	g = gcd ( p, q );
	cout << p/g << "/" << q/g << endl;
}