#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;
const int MAXN = 500005;

int ori[MAXN], res[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	int n, last, llast, beg, c01, cc;
	cin >> n;
	lp ( i, 1, (n+1) ) cin >> ori[i];
	ori[0] = ori[1];
	ori[n+1] = ori[n];
	lp ( i, 0, (n+2) ) res[i] = ori[i];

	cc = 0;
	c01 = 0;
	beg = 0;
	last = 1;
	llast = 0;
	lp ( i, 1, (n+2) ){
		if ( ori[i] == ori[i-1] ){
			last++;
			if ( last == 2 ){
				cc = max ( cc, c01 / 2 );

				if ( ori[beg] == ori[i] ){
					for ( int j = beg; j <= i; j++ ) res[j] = ori[i];
				}else if ( c01 > 1 ){
					for ( int j = beg; j < beg+llast+c01/2; j++ ) res[j] = ori[beg];
					for ( int j = i-c01/2-1; j <= i; j++ ) res[j] = ori[i];
				}

				beg = i-1;
				c01 = 0;
			}
		}else{   // ori[i] != ori[i-1]
			c01++;
			if ( last > 1 ) llast = last;
			last = 1;
		}
	}

	cout << cc << endl;
	lp ( i, 1, (n+1) ) cout << res[i] << " ";
	cout << endl;
}