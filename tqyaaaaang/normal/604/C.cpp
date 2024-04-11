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

	int n, ans, cc, c2 = 0;
	bool c3 = false;
	char now;
	string ansstr;

	cin >> n >> ansstr;

	now = ansstr[0];
	ans = 1;
	cc = 1;
	lp ( i, 1, n ){
		char &here = ansstr[i];

		if ( here == now ){
			cc++;
		}else{
			if ( cc >= 3 ) c3 = true;
			if ( cc == 2 ) c2++;

			cc = 1;
			ans++;
			now = here;
		}
	}

	if ( cc >= 3 ) c3 = true;
	if ( cc == 2 ) c2++;

	if ( c3 || ( c2 >= 2 ) ) ans += 2;
	else if ( c2 ) ans += 1;

	cout << ans << endl;
}