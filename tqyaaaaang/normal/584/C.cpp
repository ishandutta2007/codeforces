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
const int MAXN = 100007;

char s1[MAXN], s2[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	int n, t, diff;

	cin >> n >> t;;

	cin >> s1 >> s2;
	
	int cc = 0;
	lp ( i, 0, n ){
		if ( s1[i] != s2[i] ) cc++;
	}
	
	diff = cc;
	t -= ( cc + 1 ) / 2;
	if ( t < 0 ){
		cout << -1 << endl;
	}else{
		if ( cc & 1 ) cc--;
		while ( n - diff < t && cc > 0 ) t--, cc -= 2;

		if ( n - diff < t ){
			cout << -1 << endl;
		}else{
			lp ( i, 0, n ){
				if ( s1[i] != s2[i] ){
					if ( cc ){
						cout << ( ( cc % 2 ) ? s1[i] : s2[i] );
						cc--;
					}else{
						for ( char c = 'a'; c <= 'z'; c++ )
							if ( ( c != s1[i] ) && ( c != s2[i] ) ){
								cout << c;
								break;
							}
					}
				}else{
					if ( t ){
						for ( char c = 'a'; c <= 'z'; c++ )
							if ( c != s1[i] ){
								cout << c;
								break;
							}
						t--;
					}else
						cout << s1[i];
				}
			}
		}

		cout << endl;
	}
}