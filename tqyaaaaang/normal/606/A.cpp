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

	int have[3], req[3], make = 0, want = 0;

	cin >> have[0] >> have[1] >> have[2] >> req[0] >> req[1] >> req[2];

	lp ( i, 0, 3 ){
		if ( have[i] > req[i] ){
			make += ( have[i] - req[i] ) / 2;
		}else{
			want += req[i] - have[i];
		}
	}
	
	if ( make >= want ) cout << "Yes" << endl; else cout << "No" << endl;
}