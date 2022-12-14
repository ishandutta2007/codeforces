#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( int loop = start; loop < end; loop++ )
#define lpd(loop,start,end) for ( int loop = start; loop > end; loop-- )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; loop++ )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; loop-- )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 300007;

char s[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	int n, m, dot, g, p;
	char rep;

	cin >> n >> m;
	cin >> s;

	dot = g = 0;
	if ( s[0] == '.' ) dot++;
	lp ( i, 1, n ){
		if ( s[i] == '.' ){
			dot++;
		}else{
			if ( s[i-1] == '.' ) g++;
		}
	}

	if ( s[n-1] == '.' ) g++;

	lp ( i, 0, m ){
		cin >> p >> rep;
		p--;

		if ( rep == '.' ){
			if ( s[p] != '.' ){
				if ( p == 0 ){
					if ( s[p+1] != '.' ) g++;
				}else if ( p == n-1 ){
					if ( s[p-1] != '.' ) g++;
				}else{
					if ( s[p-1] == '.' && s[p+1] == '.' ) g--;
					else if ( s[p-1] != '.' && s[p+1] != '.' ) g++;
				}

				dot++;
			}
		}else{
			if ( s[p] == '.' ){
				if ( p == 0 ){
					if ( s[p+1] != '.' ) g--;
				}else if ( p == n-1 ){
					if ( s[p-1] != '.' ) g--;
				}else{
					if ( s[p-1] == '.' && s[p+1] == '.' ) g++;
					else if ( s[p-1] != '.' && s[p+1] != '.' ) g--;
				}

				dot--;
			}
		}

		s[p] = rep;
		cout << dot - g << endl;
	}
}